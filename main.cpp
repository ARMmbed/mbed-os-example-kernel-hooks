/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "mbed.h"
#include "Kernel.h"

/* Entry function for test thread */
void test_thread(void)
{
    printf("\ntest thread started");
    wait(2.0);
    printf("\ntest thread exiting");
}

/* Hook function for thread terminate */
void thread_terminate_hook(osThreadId_t id)
{
    printf("\ntest thread terminated");
}

/* Hook function for idle task */
void test_idle_hook(void)
{
    printf("\nidle hook invoked\n");
    //Now remove this hook and re-instate the original hook by passing a NULL for the idle hook funtion pointer
    Kernel::attach_idle_hook(NULL);
}

// main() runs in its own thread in the OS
int main() {
  
    printf("\nattach_thread_terminate_hook demo:\n");
    
    //Attach a hook for thread terminate event
    Kernel::attach_thread_terminate_hook(thread_terminate_hook);
    Thread *newThread = new Thread(osPriorityNormal1, 512, NULL, NULL);
    newThread->start(callback(test_thread));
    wait(4.0);
    
    printf("\n\nattach_idle_hook demo:\n");
    //Attach a hook for idle task
    Kernel::attach_idle_hook(test_idle_hook);
    
    while(1) {
        wait(3.0);
    }
    printf("\n\n");
}


