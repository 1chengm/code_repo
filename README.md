# code_repo

这是一个用于整理和保存 C / C++ 学习代码的仓库，包含基础算法练习、网络编程实验以及一个简单的宾馆管理课程作业。

This repository collects C / C++ practice code, including algorithm exercises, socket programming demos, and a simple hotel management homework project.

## 目录结构

### `common_code/`
- `int_to_charArray.cpp`：与数字处理相关的小练习代码。

### `cpp_hotel_management_homework/`
- `main.cpp`：一个基于命令行的宾馆房间管理程序。
- 支持添加房间、客人入住、客人退房、浏览房间信息和查询空房间。
- 运行时会读取或写入 `rooms.txt` 与 `guests.txt`。

### `httpserver&client&server/`
- `server.cpp`：基于 socket 的简单服务端示例。
- `client.cpp`：与服务端通信的客户端示例。
- `myhttp.cpp`：HTTP 相关实验代码。
- 这些程序使用了系统网络头文件，更适合在 Linux 环境下编译运行。

### `total_find/`
- `binary.cpp`：二分查找示例，会先对数组排序，再查找用户输入的元素。

### `total_sort/`
- 收集了多种排序算法练习代码，例如：
  - `bucket_sort.cpp`
  - `count_sort.cpp`
  - `heap_sort.cpp`
  - `insertion.cpp`
  - `merge_sort.cpp`
  - `quick_sort.cpp`
  - `three_quick.cpp`

### 根目录
- `test.cpp`：独立的练习代码示例。

## 编译与运行

本仓库当前没有统一的构建系统（例如 `CMakeLists.txt` 或 `Makefile`），示例代码可以按文件分别编译。

### 编译普通 C++ 示例

```bash
g++ -std=c++11 -o quick_sort total_sort/quick_sort.cpp
./quick_sort
```

### 编译宾馆管理程序

```bash
g++ -std=c++11 -o hotel cpp_hotel_management_homework/main.cpp
./hotel
```

> 提示：运行宾馆管理程序前，可以先准备 `rooms.txt`，每行放一个房间号。

### 编译 socket 示例

```bash
g++ -std=c++11 -o server "httpserver&client&server/server.cpp"
g++ -std=c++11 -o client "httpserver&client&server/client.cpp"
```

> 注意：客户端和服务端代码中使用了固定 IP 地址，运行前可能需要根据本机网络环境修改源码中的地址配置。

## 说明

- 这是一个学习性质的代码仓库，主要用于归档练习和课程作业。
- 不同目录中的代码彼此相对独立，可以按需单独查看、编译和运行。
- 仓库中若存在 `.exe` 文件，它们通常是历史编译产物，不是源码的一部分。
