from alpine:3.12.0
RUN apk update && apk add make g++ glew-dev glfw-dev mesa-dri-vmwgfx
WORKDIR /usr/src/app
RUN adduser -D --gecos '' user
USER user
