cmake_minimum_required(VERSION 3.16)
project(HumanResourceMachine)

# 指定c++标准的版本
set(CMAKE_CXX_STANDARD 17)
# 设置Qt5的cmake模块所在目录，如果不设置将使用系统提供的版本
set(CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.13.1\\5.13.1\\mingw73_32")
#包含当前项目路径
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 自动调用moc，uic，rcc处理qt的扩展部分
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

#找到对应的qt模块，名字为qmake中QT += 中的name首字母大写后加上Qt5前缀
find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Gui)


# 设置Qt5的cmake模块所在目录，如果不设置将使用系统提供的版本
add_executable(HumanResourceMachine
        main.cpp
        mainwindow.cpp mainwindow.h mainwindow.ui levelchoosedialog.cpp levelchoosedialog.h levelchoosedialog.ui CoreThread.cpp CoreThread.h)

# 设置目标编译路径
target_link_libraries(HumanResourceMachine Qt5::Widgets)