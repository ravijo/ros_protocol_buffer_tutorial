Older versions of `protobuf` might be installed already. Hence, in order to ignore the conflict, we are using locally installed `protobuf`

# Steps to setup `protobuf`
1. *Using pre-build binaries*
    1. Download the pre-build binaries `protobuf-3.5.0.tar.gz` from release page. The URL of the file is [here](https://github.com/ravijo/ros_protocol_buffer_tutorial/releases/download/1/protobuf-3.5.0.tar.gz)
    1. Place extracted `protobuf-3.5.0.tar.gz` here. The directory structure should look as following:
1. *Compile from source*
    1. If setup using pre-build binaries don't work, please setup by compiling the source code.
    1. Follow the instructions written [here](https://github.com/google/protobuf/blob/master/src/README.md). Use `./configure --prefix=PWD`
```
lib
└── protobuf-3.5.0
    ├── bin
    ├── include
    └── lib
```

# Note
1. The pre-build binaries are tested on ROS Indigo in 64Bit Ubuntu 14.04.5 LTS, 8GB RAM, Intel Core i7-2600 3.40GHz x 8 CPU with kernel 4.4.0-59-generic and gcc 4.8.4.
