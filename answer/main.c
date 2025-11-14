#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


void taskFirst(void *p) {
    int count = 0;
    while(1){
        printf("hello task1: count %d\n", count++);
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

void taskSecond(void *p) {
    int count = 0;
    while (1){
        printf("hello task2: count %d\n", count++);
        vTaskDelay(500/portTICK_PERIOD_MS);
    }

}

void taskThird(void *p) {
    int count = 0;
    while (1){
        printf("hello task3: count %d\n", count++);
        vTaskDelay(500/portTICK_PERIOD_MS);
    }
}


void app_main(void)
{

    xTaskCreate(taskFirst, "task1", 2048, NULL, 3, NULL);
    xTaskCreate(taskSecond, "task2", 2048, NULL, 2, NULL);
    xTaskCreate(taskThird, "task3", 2048, NULL, 1, NULL);

}