/*
 * @Date: 2021-10-15 02:56:42
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-10-15 03:04:32
 */
#include <iostream>

class apple
{
 private:
    int num;
    apple(const apple&) = delete;
    apple& operator =(const apple&) = delete;

    
    
 public:
    apple(int a): num(a){
        
    }

    ~apple() {
        std::cout<<"destructed"<<std::endl;
    }

    void show() {
        printf("%p ", this);
        std::cout<<num<<std::endl;
    }
};

int main(int argc, char const *argv[])
{
    auto ptr = std::make_shared<apple>(4);
    apple& entity = *ptr.get();
    entity.show();
    ptr.reset();
    printf("explicitly destroyed pointer\n");
    entity.show();
    // ptr.get()->show();
    return 0;
}
