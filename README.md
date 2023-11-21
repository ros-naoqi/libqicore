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
Humble | [![ros2-humble-jammy-bin-status-badge](https://build.ros2.org/job/Hbin_uJ64__naoqi_libqicore__ubuntu_jammy_amd64__binary/badge/icon)](https://build.ros2.org/job/Hbin_uJ64__naoqi_libqicore__ubuntu_jammy_amd64__binary) | [![ros2-humble-jammy-src-status-badge](https://build.ros2.org/job/Hsrc_uJ__naoqi_libqicore__ubuntu_jammy__source/badge/icon)](https://build.ros2.org/job/Hsrc_uJ__naoqi_libqicore__ubuntu_jammy__source) | [![ros2-humble-jammy](https://github.com/ros-naoqi/libqicore/actions/workflows/humble_jammy.yml/badge.svg?branch=ros2)](https://github.com/ros-naoqi/libqicore/actions/workflows/humble_jammy.yml)
Iron | [![ros2-iron-jammy-bin-status-badge](https://build.ros2.org/job/Ibin_uJ64__naoqi_libqicore__ubuntu_jammy_amd64__binary/badge/icon)](https://build.ros2.org/job/Ibin_uJ64__naoqi_libqicore__ubuntu_jammy_amd64__binary) | [![ros2-iron-jammy-src-status-badge](https://build.ros2.org/job/Isrc_uJ__naoqi_libqicore__ubuntu_jammy__source/badge/icon)](https://build.ros2.org/job/Isrc_uJ__naoqi_libqicore__ubuntu_jammy__source) | [![ros2-iron-jammy](https://github.com/ros-naoqi/libqicore/actions/workflows/iron_jammy.yml/badge.svg?branch=ros2)](https://github.com/ros-naoqi/libqicore/actions/workflows/iron_jammy.yml)
