# naoqi_libqicore

This fork is used to define the __naoqi_libqicore__ ROS2 package, based on [__libqicore__](https://github.com/aldebaran/libqicore).

## Compilation
To compile __naoqi_libqicore__, clone this repository in a ROS workspace and use the `colcon build` command. Please note that [__naoqi_libqi__](https://github.com/ros-naoqi/libqi) is a dependency of that project, you should have the package `ros-distro-naoqi-libqi` installed, or build the naoqi_libqi project from source in the same workspace.

Please note that you should checkout the branch corresponding to your ROS distro (eg. `galactic-devel` for Galactic, `foxy-devel` for Foxy, etc...)

## Working from container

You can work on this project from a dev container:

```bash
docker build -t ros2-naoqi-libqicore --target dev_with_deps_sources .
docker run --volume=.:/home/user/ws/src/naoqi-libqicore -it ros2-naoqi-libqicore
```

Edit the [`Dockerfile`](./Dockerfile) to set the target distro you want to work on.

## Status
The source and binary status reflect the buildfarm builds for this package. The github build specifies wether it is possible to build this project from source, assuming that the upstream packages have been released (`naoqi_libqi`).

ROS Distro | Binary Status | Source Status | Github Build
|-------------------|-------------------|-------------------|-------------------|
Humble | | | [![ros2-humble-jammy](https://github.com/ros-naoqi/libqicore/actions/workflows/humble_jammy.yml/badge.svg)](https://github.com/ros-naoqi/libqicore/actions/workflows/humble_jammy.yml)
Galactic | [![Build Status](https://build.ros2.org/job/Gbin_uF64__naoqi_libqicore__ubuntu_focal_amd64__binary/badge/icon)](https://build.ros2.org/job/Gbin_uF64__naoqi_libqicore__ubuntu_focal_amd64__binary/) | [![Build Status](https://build.ros2.org/job/Gsrc_uF__naoqi_libqicore__ubuntu_focal__source/badge/icon)](https://build.ros2.org/job/Gsrc_uF__naoqi_libqicore__ubuntu_focal__source/) | [![ros2-galactic-focal](https://github.com/ros-naoqi/libqicore/actions/workflows/galactic_focal.yml/badge.svg)](https://github.com/ros-naoqi/libqicore/actions/workflows/galactic_focal.yml)
Foxy | [![Build Status](https://build.ros2.org/job/Fbin_uF64__naoqi_libqicore__ubuntu_focal_amd64__binary/badge/icon)](https://build.ros2.org/job/Fbin_uF64__naoqi_libqicore__ubuntu_focal_amd64__binary/) | [![Build Status](https://build.ros2.org/job/Fsrc_uF__naoqi_libqicore__ubuntu_focal__source/badge/icon)](https://build.ros2.org/job/Fsrc_uF__naoqi_libqicore__ubuntu_focal__source/) | [![ros2-foxy-focal](https://github.com/ros-naoqi/libqicore/actions/workflows/foxy_focal.yml/badge.svg)](https://github.com/ros-naoqi/libqicore/actions/workflows/foxy_focal.yml)