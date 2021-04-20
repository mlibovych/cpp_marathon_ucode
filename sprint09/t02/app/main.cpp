/* app/main.cpp */
#include <fstream>
#include <iostream>
#include <thread>
#include "MultithreadedFileHandler.h"
#include "Worker.h"

int main(int argc, char** argv) {
    if (argc == 3) {
        std::ifstream f1(argv[1]);
        std::ifstream f2(argv[2]);

        if (f1.good() && f2.good()) {
            MultithreadedFileHandler obj;
            Worker worker;

            worker.startNewThread(&MultithreadedFileHandler::processFile, &obj);
            worker.startNewThread(&MultithreadedFileHandler::loadFile, &obj, argv[1]);

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::cout << "-----1 second sleep-----" << std::endl;

            worker.startNewThread(&MultithreadedFileHandler::processFile, &obj);
            worker.startNewThread(&MultithreadedFileHandler::loadFile, &obj, argv[2]);

            worker.joinAllThreads();
        } else {
            std::cerr << "error" << std::endl;
            return -1;
        }
    } else {
        std::cerr << "usage: ./multithreadedFileHandler [file1] [file2]" << std::endl;
        return -1;
    }
    return 0;
}
