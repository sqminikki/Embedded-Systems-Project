# Testing and Running on Milk-V DUO

## TESTING on the Milk-V

### 1. Configure CMake
- `docker run --rm -v $PWD:/app (name of docker image) bash -c "mkdir build && cd build && cmake .."`

### 2. Compile
- `docker run --rm -v $PWD:/app -it (name of docker image) make`

### 3. Push `test` file to Duo
- `scp build/test root@192.168.42.1:/root/`

### 4. Login to the DUO `scp root@192.168.42.1`
- make the file executable: `chmod +x test`
- Run the test: `./test`

## RUNNING on the Milk-V
### 1. Configure CMake
- `docker run --rm -v $PWD:/app (name of docker image) bash -c "mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=/app/milkv_duo.cmake .." `

### 2. Compile
- `docker run --rm -v $PWD:/app -it (name of docker image) make`

### 3. Push the `morse_blink_led` file to the duo
- `scp build/test root@192.168.42.1:/root/`

### 4. Login to the duo `ssh root@192.168.42.1`
- Make the file executable: `chmod +x morse_blink_led`
- Run the test: `./morse_blink_led`