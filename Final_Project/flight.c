#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char flight_number[5];
    char departure_city[50];
    char destination_city[50];
    char departure_datetime[50];
    char arrival_datetime[50];
    int first_class_available;
    int first_class_sold;
    int coach_available;
    int coach_sold;
    int is_active; 
} Flight;

void create_flight();
void delete_flight();
void update_flight();
void make_reservation();
void cancel_reservation();
void display_flights();
Flight* find_flight(char* flight_number);
int get_flight_count();
void write_flight(Flight* flight, int position);
Flight read_flight(int position);
void initialize_file();

int main(){
    initialize_file(); 
    int choice;
    
    while(1){
        printf("\nAirline Reservation System\n");
        printf("1. Create Flight\n");
        printf("2. Delete Flight\n");
        printf("3. Update Flight\n");
        printf("4. Make Reservation\n");
        printf("5. Cancel Reservation\n");
        printf("6. Display Flights\n");
        printf("7. Exit\n");
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1: create_flight(); break;
            case 2: delete_flight(); break;
            case 3: update_flight(); break;
            case 4: make_reservation(); break;
            case 5: cancel_reservation(); break;
            case 6: display_flights(); break;
            case 7: 
                printf("Program Closed\n");
                exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

void initialize_file(){
    FILE* file = fopen("flights.txt", "rb");
    if(!file){
        file = fopen("flights.txt", "wb");
        if(!file){
            printf("Error creating file!\n");
            exit(1);
        }
        int count = 0;
        fwrite(&count, sizeof(int), 1, file);
        fclose(file);
    }
    else{
        fclose(file);
    }
}

int get_flight_count(){
    FILE* file = fopen("flights.txt", "rb");
    if(!file) return 0;
    
    int count;
    fread(&count, sizeof(int), 1, file);
    fclose(file);
    return count;
}

void write_flight(Flight* flight, int position){
    FILE* file = fopen("flights.txt", "r+b");
    if(!file){
        printf("Error opening file!\n");
        return;
    }

    fseek(file, sizeof(int) + position * sizeof(Flight), SEEK_SET);
    fwrite(flight, sizeof(Flight), 1, file);
    fclose(file);
}

Flight read_flight(int position){
    FILE* file = fopen("flights.txt", "rb");
    Flight flight ={0};  
    
    if(!file){
        printf("Error opening file!\n");
        return flight;
    }
    
    fseek(file, sizeof(int) + position * sizeof(Flight), SEEK_SET);
    fread(&flight, sizeof(Flight), 1, file);
    fclose(file);
    return flight;
}

void update_flight_count(int count){
    FILE* file = fopen("flights.txt", "r+b");
    if(!file){
        printf("Error opening file!\n");
        return;
    }
    
    fseek(file, 0, SEEK_SET); 
    fwrite(&count, sizeof(int), 1, file);
    fclose(file);
}

void create_flight(){
    int count = get_flight_count();
    if(count >= 1000){
        printf("Cannot add more flights. Maximum limit reached!\n");
        return;
    }
    
    Flight new_flight = {0};  
    new_flight.is_active = 1;  
    
    printf("Enter flight number (A01-J99): ");
    fgets(new_flight.flight_number, 50, stdin);
    new_flight.flight_number[strcspn(new_flight.flight_number, "\n")] = 0;
    
    for(int i = 0; i < count; i++){
        Flight existing = read_flight(i);
        if(existing.is_active && strcmp(existing.flight_number, new_flight.flight_number) == 0){
            printf("Flight already exists!\n");
            return;
        }
    }
    
    printf("Enter departure city: ");
    fgets(new_flight.departure_city, 50, stdin);
    new_flight.departure_city[strcspn(new_flight.departure_city, "\n")] = 0;
    
    printf("Enter destination city: ");
    fgets(new_flight.destination_city, 50, stdin);
    new_flight.destination_city[strcspn(new_flight.destination_city, "\n")] = 0;
    
    printf("Enter departure date and time (DD/MM/YYYY HH:MM): ");
    fgets(new_flight.departure_datetime, 50, stdin);
    new_flight.departure_datetime[strcspn(new_flight.departure_datetime, "\n")] = 0;
    
    printf("Enter arrival date and time (DD/MM/YYYY HH:MM): ");
    fgets(new_flight.arrival_datetime, 50, stdin);
    new_flight.arrival_datetime[strcspn(new_flight.arrival_datetime, "\n")] = 0;
    
    int total_first_class;
    printf("Enter total number of first-class seats: ");
    scanf("%d", &total_first_class);
    getchar(); 

    printf("Enter number of first-class seats already sold: ");
    scanf("%d", &new_flight.first_class_sold);
    getchar(); 

    if(new_flight.first_class_sold > total_first_class){
        printf("Error: Sold seats cannot be more than total seats!\n");
        return;
    }
    new_flight.first_class_available = total_first_class - new_flight.first_class_sold;
    
    int total_coach;
    printf("Enter total number of coach seats: ");
    scanf("%d", &total_coach);
    getchar();

    printf("Enter number of coach seats already sold: ");
    scanf("%d", &new_flight.coach_sold);
    getchar();

    if(new_flight.coach_sold > total_coach){
        printf("Error: Sold seats cannot be more than total seats!\n");
        return;
    }
    new_flight.coach_available = total_coach - new_flight.coach_sold;
    
    write_flight(&new_flight, count);
    count++;
    update_flight_count(count);
    
    printf("Flight created successfully!\n");
}

void delete_flight(){
    char flight_number[5];
    printf("Enter flight number (A01-J99): ");
    fgets(flight_number, 5, stdin);
    flight_number[strcspn(flight_number, "\n")] = 0;
    
    int count = get_flight_count();
    for(int i = 0; i < count; i++){
        Flight flight = read_flight(i);
        if(flight.is_active && strcmp(flight.flight_number, flight_number) == 0){
            flight.is_active = 0;  
            write_flight(&flight, i);
            printf("Flight deleted successfully!\n");
            return;
        }
    }
    printf("Flight not found!\n");
}

void update_flight(){
    char flight_number[5];
    printf("Enter flight number (A01-J99): ");
    fgets(flight_number, 5, stdin);
    flight_number[strcspn(flight_number, "\n")] = 0;
    
    int count = get_flight_count();
    for(int i = 0; i < count; i++){
        Flight flight = read_flight(i);
        if(flight.is_active && strcmp(flight.flight_number, flight_number) == 0){
            printf("Enter new departure city (press enter to skip): ");
            char input[50];
            fgets(input, 50, stdin);
            input[strcspn(input, "\n")] = 0;
            if(strlen(input) > 0) strcpy(flight.departure_city, input);
            
            printf("Enter new destination city (press enter to skip): ");
            fgets(input, 50, stdin);
            input[strcspn(input, "\n")] = 0;
            if(strlen(input) > 0) strcpy(flight.destination_city, input);
            
            printf("Enter new departure date and time (DD/MM/YYYY HH:MM) (press enter to skip): ");
            fgets(input, 50, stdin);
            input[strcspn(input, "\n")] = 0;
            if(strlen(input) > 0) strcpy(flight.departure_datetime, input);
            
            printf("Enter new arrival date and time (DD/MM/YYYY HH:MM) (press enter to skip): ");
            fgets(input, 50, stdin);
            input[strcspn(input, "\n")] = 0;
            if(strlen(input) > 0) strcpy(flight.arrival_datetime, input);

            printf("Update first-class seats? (y/n): ");
            fgets(input, 50, stdin);
            if(input[0] == 'y' || input[0] == 'Y'){
                int new_total;
                printf("Enter new total first-class seats: ");
                scanf("%d", &new_total);
                getchar(); 
                
                if(new_total < flight.first_class_sold){
                    printf("Error: New total cannot be less than sold seats!\n");
                }
                else{
                    flight.first_class_available = new_total - flight.first_class_sold;
                }
            }

            printf("Update coach seats? (y/n): ");
            fgets(input, 50, stdin);
            if(input[0] == 'y' || input[0] == 'Y'){
                int new_total;
                printf("Enter new total coach seats: ");
                scanf("%d", &new_total);
                getchar(); 
                
                if(new_total < flight.coach_sold){
                    printf("Error: New total cannot be less than sold seats!\n");
                }
                else{
                    flight.coach_available = new_total - flight.coach_sold;
                }
            }
            
            write_flight(&flight, i);
            printf("Flight updated successfully!\n");
            return;
        }
    }
    printf("Flight not found!\n");
}

void display_flights(){
    int count = get_flight_count();
    if(count == 0){
        printf("No flights available!\n");
        return;
    }
    
    printf("\nFlight List:\n\n");
    
    for(int i = 0; i < count; i++){
        Flight flight = read_flight(i);
        if(flight.is_active){
            printf("Flight Number\t\t: %s\n", flight.flight_number);
            printf("Departure\t\t: %s\n", flight.departure_city);
            printf("Destination\t\t: %s\n", flight.destination_city);
            printf("Departure Time\t\t: %s\n", flight.departure_datetime);
            printf("Arrival Time\t\t: %s\n", flight.arrival_datetime);
            printf("First-Class Available\t: %d\n", flight.first_class_available);
            printf("First-Class Sold\t: %d\n", flight.first_class_sold);
            printf("Coach Available\t\t: %d\n", flight.coach_available);
            printf("Coach Sold\t\t: %d\n\n", flight.coach_sold);
        }
    }
}

void display_single_flight(Flight flight){
    printf("\nFlight Details:\n");
    printf("Flight Number: %s\n", flight.flight_number);
    printf("\tDeparture: %s\n", flight.departure_city);
    printf("\tDestination: %s\n", flight.destination_city);
    printf("\tDeparture Time: %s\n", flight.departure_datetime);
    printf("\tArrival Time: %s\n", flight.arrival_datetime);
    printf("\tFirst-Class Available: %d\n", flight.first_class_available);
    printf("\tFirst-Class Sold: %d\n", flight.first_class_sold);
    printf("\tCoach Available: %d\n", flight.coach_available);
    printf("\tCoach Sold: %d\n", flight.coach_sold);
}

void make_reservation(){
    char flight_number[5];
    printf("Enter flight number (A01-J99): ");
    fgets(flight_number, 5, stdin);
    flight_number[strcspn(flight_number, "\n")] = 0;
    
    int count = get_flight_count();
    for(int i = 0; i < count; i++){
        Flight flight = read_flight(i);
        if(flight.is_active && strcmp(flight.flight_number, flight_number) == 0){
            display_single_flight(flight);
            
            printf("\nSelect class (1 for First Class, 2 for Coach): ");
            int class_choice;
            scanf("%d", &class_choice);
            getchar(); 
            
            if(class_choice == 1){
                if(flight.first_class_available > 0){
                    flight.first_class_available--;
                    flight.first_class_sold++;
                    write_flight(&flight, i);
                    printf("First class reservation successful!\n");
                    display_single_flight(flight); 
                }
                else{
                    printf("Sorry, no first class seats available!\n");
                }
            } 
            else if(class_choice == 2){
                if(flight.coach_available > 0){
                    flight.coach_available--;
                    flight.coach_sold++;
                    write_flight(&flight, i);
                    printf("Coach class reservation successful!\n");
                    display_single_flight(flight);
                }
                else{
                    printf("Sorry, no coach seats available!\n");
                }
            }
            else{
                printf("Invalid class selection!\n");
            }
            return;
        }
    }
    printf("Flight not found!\n");
}

void cancel_reservation(){
    char flight_number[5];
    printf("Enter flight number (A01-J99): ");
    fgets(flight_number, 5, stdin);
    flight_number[strcspn(flight_number, "\n")] = 0;
    
    int count = get_flight_count();
    for(int i = 0; i < count; i++){
        Flight flight = read_flight(i);
        if(flight.is_active && strcmp(flight.flight_number, flight_number) == 0){
            display_single_flight(flight);
            
            printf("\nSelect class (1 for First Class, 2 for Coach): ");
            int class_choice;
            scanf("%d", &class_choice);
            getchar(); 
            
            if(class_choice == 1){
                if(flight.first_class_sold > 0){
                    flight.first_class_available++;
                    flight.first_class_sold--;
                    write_flight(&flight, i);
                    printf("First class reservation cancelled successfully!\n");
                    display_single_flight(flight); 
                }
            else{
                    printf("No first class reservations to cancel!\n");
                }
            } 
            else if(class_choice == 2){
                if(flight.coach_sold > 0){
                    flight.coach_available++;
                    flight.coach_sold--;
                    write_flight(&flight, i);
                    printf("Coach class reservation cancelled successfully!\n");
                    display_single_flight(flight); 
                }
                else{
                    printf("No coach reservations to cancel!\n");
                }
            }
            else{
                printf("Invalid class selection!\n");
            }
            return;
        }
    }
    printf("Flight not found!\n");
}
