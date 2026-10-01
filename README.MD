# Ada

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
$ build.sh --prefix ada-build
```
