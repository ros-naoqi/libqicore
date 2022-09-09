# naoqi_libqicore

This fork is used to define the __naoqi_libqicore__ ROS package, based on [__libqicore__](https://github.com/aldebaran/libqicore).

## Compilation
To compile __naoqi_libqicore__, clone this repository in a ROS workspace and use the `catkin_make` command. Please note that [__naoqi_libqi__](https://github.com/ros-naoqi/libqi) is a dependency of that project, you should have the package `ros-distro-naoqi-libqi` installed, or build the naoqi_libqi project from source in the same workspace.

Please note that you should checkout the branch corresponding to your ROS distro (eg. `melodic-devel` for Melodic, `noetic-devel` for Noetic, etc...)

## Status 
The source and binary status reflect the buildfarm builds for this package. The github build specifies wether it is possible to build this project from source, assuming that the upstream packages have been released (`naoqi_libqi`).


ROS Distro | Binary Status | Source status | Github Build |
|-------------------|-------------------|-------------------|-------------------|
Noetic | [![Build Status](https://build.ros.org/job/Nbin_uf64__naoqi_libqicore__ubuntu_focal_amd64__binary/badge/icon)](https://build.ros.org/job/Nbin_uf64__naoqi_libqicore__ubuntu_focal_amd64__binary/) | [![Build Status](https://build.ros.org/job/Nsrc_uF__naoqi_libqicore__ubuntu_focal__source/badge/icon)](https://build.ros.org/job/Nsrc_uF__naoqi_libqicore__ubuntu_focal__source/) | [![ros-noetic-focal](https://github.com/ros-naoqi/libqicore/actions/workflows/noetic_focal.yml/badge.svg)](https://github.com/ros-naoqi/libqicore/actions/workflows/noetic_focal.yml) 
Melodic | [![Build Status](https://build.ros.org/job/Mbin_ub64__naoqi_libqicore__ubuntu_bionic_amd64__binary/badge/icon)](https://build.ros.org/job/Mbin_ub64__naoqi_libqicore__ubuntu_bionic_amd64__binary/) | [![Build Status](https://build.ros.org/job/Msrc_uB__naoqi_libqicore__ubuntu_bionic__source/badge/icon)](https://build.ros.org/job/Msrc_uB__naoqi_libqicore__ubuntu_bionic__source/) | [![ros-melodic-bionic](https://github.com/ros-naoqi/libqicore/actions/workflows/melodic_bionic.yml/badge.svg)](https://github.com/ros-naoqi/libqicore/actions/workflows/melodic_bionic.yml)
Kinetic | ![passing](https://raw.githubusercontent.com/jenkinsci/embeddable-build-status-plugin/7c7eedc7617851f07a1f09629c33fee11cff50ab/src/doc/flat_unconfigured.svg) | ![passing](https://raw.githubusercontent.com/jenkinsci/embeddable-build-status-plugin/7c7eedc7617851f07a1f09629c33fee11cff50ab/src/doc/flat_unconfigured.svg) | [![ros-kinetic-xenial](https://github.com/ros-naoqi/libqicore/actions/workflows/kinetic_xenial.yml/badge.svg)](https://github.com/ros-naoqi/libqicore/actions/workflows/kinetic_xenial.yml)