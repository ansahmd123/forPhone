// 1.using concept of mutex lock

// #include<iostream>
// #include<thread>
// #include<mutex>

// using namespace std;

// mutex m;

// void printMessage(int id){
//     m.lock();
//     cout<<"Thread "<<id<<" is executing."<<endl;
//     m.unlock();
// }

// int main(){
//     thread t1(printMessage,1);
//     thread t2(printMessage,2);

//     t1.join();
//     t2.join();
// }

// 2.using test and set lock

// #include<iostream>
// #include<thread>
// #include<atomic>

// using namespace std;

// atomic<bool> lock(false);

// void printMessage(int id){
//     while(lock.exchange(true)) {}
//     cout<<"Thread "<<id<<" is executing."<<endl;
//     lock.store(false);
// }

// int main(){
//     std::thread t1 (printMessage,1);
//     std::thread t2 (printMessage,2);

//     t1.join();
//     t2.join();
//     return 0;
// }

// 3.using semaphores
// #include<iostream>
// #include<thread>
// #include<mutex>
// #include<semaphore.h>

// using namespace std;

// sem_t sem;

// void printMessage(int id){
//     sem_wait(&sem);
//     cout<<"Thread "<<id<<" is executing."<<endl;
//     sem_post(&sem);

// }

// int main(){
//     sem_init(&sem,0,1);
//     thread t1(printMessage,1);
//     thread t2(printMessage,2);

//     t1.join();
//     t2.join();
//     sem_destroy(&sem);
//     return 0;
// }

// 4.using turn variable
//  #include<iostream>
//  #include<thread>
//  using namespace std;

// volatile int turn = 1;

// void printMessage(int id){
//     while (true)
//     {
//         while(turn != id);
//         cout<<"Thread "<<id<<" is executing"<<endl;
//         turn = 3-id;
//     }

// }

// int main(){
//     thread t1(printMessage,1);
//     thread t2(printMessage,2);
//     t1.join();
//     t2.join();
//     return 0;
// }

// 5.using swap variable
// same as 4

// 6.using Peterson solutions

// #include<iostream>
// #include<thread>
// using namespace std;

// volatile bool flag[2] = {false,false};
// volatile int turn = 0;

// void printMessage(int id){
//     int other = 1-id;
//     flag[id] = true;
//     turn = id;

//     while(flag[other] && turn == id);
//     cout<<"Thread "<<id<<" is executing."<<endl;
//     flag[id] = false;
// }

// int main(){
//     thread t1(printMessage,0);
//     thread t2(printMessage,1);

//     t1.join();
//     t2.join();
//     return 0;
// }


// write a program to implement mutual exclusion using test and set instruction
// #include <iostream>
// #include <conio.h>

// using namespace std;

// bool lock = 0;
// bool test_and_set(bool *target)
// {
//     bool rv = *target;
//     *target = 1;
//     return rv;
// }

// void lock_()
// {
//     while (test_and_set(&lock));
// }

// void unlock_()
// {
//     lock = 0;
// }

// int main()
// {
//     lock_();
//     cout << "Critical Section" << endl;
//     unlock_();
//     cout << "Out of Critical Section" << endl;
// }
