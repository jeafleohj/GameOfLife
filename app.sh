#!/bin/bash
CMD=docker
WORKDIR=/usr/src/app
IMAGE=opengl
NAME=gol
NODE_MODULES_VOL=frontend-csc-node

menu () {
    echo -e "\e[1mValid options\e[0m"
    echo -e "\e[92mbuild\e[0m   --build docker image"
    echo -e "\e[92mrun\e[0m     --run in bg gol container"
    return
}

case $1 in
    build)
        docker build -t $IMAGE .
        ;;
    run)
        docker run --rm -td --device=/dev/dri:/dev/dri -v $PWD:/usr/src/app\
               -v $HOME/.Xauthority:/home/user/.Xauthority:rw\
               --env="DISPLAY" --net=host --name $NAME $IMAGE
        ;;
    *)
        menu
        ;;
esac
