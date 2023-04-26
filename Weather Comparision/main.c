#include <stdio.h>
#include <stdlib.h>

// struct of weather
typedef struct{
    char cityName[20];
    float temperature, windSpeed, humidity;
} weather ;

void display(weather arr[], int size){
    printf("City\t\tTemp (deg C)\t\tWind (km/h)\t\tHumidity (%%)\n");
    for (int i = 0; i<size; i++){
        printf("%-15s %-23.2f %-23.2f %.2f\n",arr[i].cityName,arr[i].temperature, arr[i].windSpeed, arr[i].humidity);
    }
}

// finding max and min same function.
void findMaxMin(weather arr[], int size){

    char choice[20];
    int maxIndex = 0;
    int minIndex = 0;

    printf("\nEnter the field to find minimum and maximum values (temp, wind, humidity): ");
    scanf("%s", choice);
    printf("\n");

    // Checking choice.
    if(strcmp(choice,"temp")==0){

        for(int i = 1; i<size; i++){

            if(arr[i].temperature > arr[maxIndex].temperature){
                maxIndex = i;
            }
        }
        for(int i = 1; i<size; i++){

            if(arr[i].temperature < arr[minIndex].temperature){
                minIndex = i;
            }
        }
        printf("Minimum value: %.2f (City: %s)\n", arr[minIndex].temperature,arr[minIndex].cityName);
        printf("Maximum value: %.2f (City: %s)\n", arr[maxIndex].temperature,arr[maxIndex].cityName);
    }


    else if(strcmp(choice,"wind")==0){

        for(int i = 1; i<size; i++){

            if(arr[i].windSpeed > arr[maxIndex].windSpeed){
                maxIndex = i;
            }
        }
        for(int i = 1; i<size; i++){
            if(arr[i].windSpeed < arr[minIndex].windSpeed){
                minIndex = i;
            }
        }

        printf("Minimum value: %.2f (City: %s)\n", arr[minIndex].windSpeed,arr[minIndex].cityName);
        printf("Maximum value: %.2f (City: %s)\n", arr[maxIndex].windSpeed,arr[maxIndex].cityName);
    }

    else if(strcmp(choice,"humidity")==0){

        for(int i = 0; i<size; i++){
            if(arr[i].humidity > arr[maxIndex].humidity){
                maxIndex = i;
            }
        }
        for(int i = 1; i<size; i++){

            if(arr[i].humidity < arr[minIndex].humidity){
                minIndex = i;
            }
        }
        printf("Minimum value: %.2f (City: %s)\n", arr[minIndex].humidity,arr[minIndex].cityName);
        printf("Maximum value: %.2f (City: %s)\n", arr[maxIndex].humidity,arr[maxIndex].cityName);
    }

    else{
        printf("Invalid value!!!\n");
    }

}

int main()
{
    // Taking number of cities.
    int n;
    printf("How many cities would you like to enter weather data for?\n");
    scanf("%d",&n);

    // creating space in memory with malloc function according to weather data type.
    weather *weathers;
    weathers = (weather *) malloc(n*sizeof(weather));

    //Taking data from user.
    for (int i = 0; i<n; i++){
        printf("Enter the city name: ");
        scanf("%s",weathers[i].cityName);
        printf("Enter the temperature: ");
        scanf("%f",&weathers[i].temperature);
        printf("Enter the wind speed: ");
        scanf("%f",&weathers[i].windSpeed);
        printf("Enter the humidity: ");
        scanf("%f",&weathers[i].humidity);
        printf("\n");
    }

    // function calling.
    display(weathers, n);
    findMaxMin(weathers, n);

    return 0;
}
