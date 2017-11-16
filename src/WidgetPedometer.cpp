#include "WidgetPedometer.h"


WidgetPedometer::WidgetPedometer(uint8_t ucItem)
{
    _Item=ucItem;
    memset(pCmdResetTopic,0,sizeof(pCmdResetTopic));
    memset(pDataCountTopic,0,sizeof(pDataCountTopic));
    sprintf(pCmdResetTopic,"channel/pedometer_%d/data/count",_Item);
    sprintf(pDataCountTopic,"channel/pedometer_%d/cmd/reset",_Item);
}

WidgetPedometer::~WidgetPedometer()
{

}

void WidgetPedometer::begin(void (*UserCallBack)(void))
{
    _EventCb=UserCallBack;
    IntoRobot.subscribe(pCmdResetTopic, NULL, this);
}

uint8_t WidgetPedometer::getReset(void)
{
    return _resetKey;
}

void WidgetPedometer::displayPedometerCount(uint32_t ucVal)
{
    IntoRobot.publish(pDataCountTopic,ucVal);
}

void WidgetPedometer::widgetBaseCallBack(uint8_t *payload, uint32_t len)
{
    if(payload[0] == '1')
    {
        _resetKey = ON;
    }
    else
    {
        _resetKey = OFF;
    }
    
    _EventCb();
}

