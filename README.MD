# Ada

![Ada - Coreutils](https://img.shields.io/badge/Ada_--_Coreutils-1000?style=flat-square&labelColor=871938&color=dedbdb)
![POSIX-Compliant](https://img.shields.io/badge/POSIX--Compliant-1000?style=flat-square&labelColor=404abf&color=dedbdb)
![Unstable](https://img.shields.io/badge/Unstable-1000?style=flat-square&labelColor=411515&color=dedbdb)

### What’s Ada?
Ada is a project to redeploy coreutils (written from scratch in C) for POSIX systems.

### How to test?

> [!WARNING]
> The complete replacement of the current coreutils by Ada is not recommended, for reasons of development that is still experimental and incomplete in certain utilities.

You can clone the repository and compile the utilities using the `build.sh` script:

```
$ git clone https://github.com/sakaki91/ada
$ cd ada
$ mkdir ada-build
$ ./build.sh --prefix ada-build
```
