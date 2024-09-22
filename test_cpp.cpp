#include <iostream>

typedef struct sensor_op {
    char name[10];               /*传感器名称*/
    int data;                    /*传感器数据*/
    int (*Read_Sensor)(void);    /*读取传感器数据的回调函数*/   //个人感觉这里可以通过宏定义来修改其接口
}sensor_Type;

/*注册对象管理类*/
class PageManger {
    typedef void(*CallbackFunction_t)(void);
    typedef void(*EventFunction_t)(void*, int);
    typedef struct {
        CallbackFunction_t SetupCallback;
        CallbackFunction_t LoopCallback;
        CallbackFunction_t ExtiCallback;
        EventFunction_t EventCallback;
    } PageList_TypeDef;

public:
    PageManger(uint8_t pageMax, uint8_t pageStackSize = 10);
    ~PageManger();

    bool PageRegister(
        uint8_t pageID,
        CallbackFunction_t setupCallback,
        CallbackFunction_t loopCallback,
        CallbackFunction_t exitCallback,
        EventFunction_t eventCallback
    );

private:

};

typedef enum 
{
    /*保留*/
    PAGE_NONE,
    /*用户界面*/

    PAGE_DialPlate,
    PAGE_MainMenu,

    /*保留*/
    PAGE_MAX
} Page_Type;

bool PageManager::PageRegister(
    uint8_t pageID,
    CallbackFunction_t setupCallback,
    CallbackFunction_t loopCallback,
    CallbackFunction_t exitCallback,
    EventFunction_t eventCallback
)
{
    if 
};

int main()
{
    
}