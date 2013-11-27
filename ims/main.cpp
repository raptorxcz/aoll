//
//  main.cpp
//  ims
//
//  Created by Kryštof Matěj on 15.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <thread>

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    while(1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        for (int i = 0; i < 100; i++) {
//            std::cout << "vojta" << std::endl;
        }
    }
    return 0;
}

