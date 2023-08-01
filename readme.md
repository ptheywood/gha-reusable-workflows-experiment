# GHA Reusable Workflows Experiment

This repository is for hands on experimentation / testing / prototyping with GitHub Actions Reusable workflows.

The target problem is a (CUDA) C++ project, using CMake, with optional configure time options (i.e an N dimentional matrix).

In the interest of CI runtime however, it will just mock up a lot of this, rather than actually include it, instead using very minimal CMake project(s) to mock this all up.

The workflows need to allow: 

+ Installing non-default dependencies (i.e. cuda, dev libs)
+ Running some builds using container images as the base (manylinux)
+ Linting
+ CMake configuration checks
+ Compilation on multiple platforms with different compiler versions / compile time options.
+ Running of tests (optional, not actually useful in the intended CUDA case)
+ Production of artifacts

Workflows should be triggered for PRs and pushes to master for "regular" CI.
A more thorough CI should be invoked manually, and on tag push.
On tag push, artifacts should be produced and attached to a release.