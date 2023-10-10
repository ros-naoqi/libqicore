ARG ROS_DISTRO=iron
FROM ros:${ROS_DISTRO} as dev
ENV ROS_DISTRO=${ROS_DISTRO}

RUN apt-get update

RUN useradd -m -s /bin/bash --user-group -G sudo --create-home --no-log-init user
RUN echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers
USER user

ENV HOME=/home/user
ENV WS=$HOME/ws
ENV SRC=$WS/src
RUN mkdir -p $SRC
WORKDIR $WS

RUN echo "source /opt/ros/${ROS_DISTRO}/setup.bash" >> ${HOME}/.bashrc
SHELL [ "/bin/bash", "-c" ]
RUN rosdep update

ENV REPO=$SRC/naoqi_libqicore
COPY --chown=user:user . $REPO
ENTRYPOINT [ "/bin/bash" ]

FROM dev as dev_with_deps
RUN rosdep install --from-paths src --ignore-src --rosdistro ${ROS_DISTRO} -y

FROM dev as dev_with_deps_sources
WORKDIR $SRC
RUN vcs import < $REPO/dependencies.repos
WORKDIR $WS
RUN rosdep install --from-paths src --ignore-src --rosdistro ${ROS_DISTRO} -y

FROM dev_with_deps as dev_prebuilt
RUN colcon build --symlink-install
