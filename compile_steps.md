# 如何编译C++代码

## 汪润

### 在Ubuntu系统上把C++编译为可执行文件

在bash中运行`g++ -O1 -I /path/to/include/ ./code_to_compile.cpp -o executable_file_name`, 其中：
1. -O1参数代表O1优化，还可以-O2（比-O1更快，但编译时间略长），-O3（比-O3更快），-Os（优化生成的可执行文件的大小），-Ofast（比-O3更疯狂的优化）
2. -I参数代表要包含的头文件目录
3. -o参数表示生成的可执行文件的名字，若省略，则默认名字为a.out

比如，`g++ -O1 -I /usr/include/eigen3/ ./eigen_learn.cpp -o eigen_learn`, 这会生成一个可执行文件，然后运行`./eigen_learn arg1 arg2 arg3`，就会执行代码，其中arg1、arg2、arg3是命令行参数，可以有多个参数，也可以没有参数
