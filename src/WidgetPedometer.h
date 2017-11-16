#ifndef WIDGET_PEDOMETER_H_
#define WIDGET_PEDOMETER_H_

#include "application.h"

class WidgetPedometer : public WidgetBaseClass
{
    public:
        WidgetPedometer(uint8_t ucItem = 0);
        ~WidgetPedometer();
        void begin(void (*UserCallBack)(void) = NULL);
        void displayPedometerCount(uint32_t ucVal);
        uint8_t getReset(void);

    private:
        char pCmdResetTopic[64];
        char pDataCountTopic[64];
        uint8_t _resetKey = 0;
        uint8_t _Item = 0;

        void (*_EventCb)(void);
        void widgetBaseCallBack(uint8_t *payload, uint32_t len);
};

#endif
