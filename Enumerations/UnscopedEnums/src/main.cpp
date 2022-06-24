// Enumerations
#include <iostream>
#include <vector>
#include <string>

enum Direction {North, South, East, West};

std::string direction_to_string(Direction dir)
{
    std::string result;
    switch (dir)
    {
    case North:
        result = "North";
        break;
    case South:
        result = "South";
        break;
    case East:
        result = "East";
        break;
    case West:
        result = "West";
        break;
    
    default:
        result = "Unknown Direction";
        break;
    }
    return result;
}


void test1()
{
    std::cout << "\n Test1 =========================" << std::endl;
    Direction _dir{North};
    std::cout << "\nDirection " << _dir << std::endl;
    std::cout << direction_to_string(_dir) << std::endl;

    _dir = West;
    std::cout << "\nDirection " << _dir << std::endl;
    std::cout << direction_to_string(_dir) << std::endl;


    _dir = Direction(100);
    std::cout << "\nDirection " << _dir << std::endl;
    std::cout << direction_to_string(_dir) << std::endl;

    _dir = static_cast<Direction>(100);
    std::cout << "\nDirection " << _dir << std::endl;
    std::cout << direction_to_string(_dir) << std::endl;
}

enum Grocery_Item{Milk, Bread, Apple, Orange};

std::ostream &operator<<(std::ostream &os, Grocery_Item grocery_item)
{
    switch(grocery_item)
    {
        case Milk:
            os << "Milk";
            break;
        case Bread:
            os << "Bread";
            break;
        case Apple:
            os << "Apple";
            break;
        case Orange:
            os << "Orange";
            break;
        default:
            os << "Invalid item";
    }
    return os;
}

bool is_valid_grocery_item(Grocery_Item grocery_Item)
{
    switch (grocery_Item)
    {
    case Milk:
    case Bread:
    case Apple:
    case Orange:
        return true;
    default:
        return false;
    }
}

void display_grocery_list(const std::vector<Grocery_Item> &grocery_list)
{
    std::cout << "Grocery List" << "\n ========================" << std::endl;
    int invalid_item_count{0};
    int valid_item_count{0};
    for(Grocery_Item grocery_item :grocery_list)
    {
        std::cout << grocery_item << std::endl;

        if(is_valid_grocery_item(grocery_item))
            valid_item_count++;
        else
            invalid_item_count++;
    }

    std::cout << "====================================" << std::endl;
    std::cout << "Valid items: " << valid_item_count << std::endl;
    std::cout << "Invalid items: " << invalid_item_count << std::endl;
    std::cout << "Total items: " << valid_item_count+invalid_item_count << std::endl;
}

void test2()
{
    std::cout << "\n Test2 =========================" << std::endl;
    std::vector<Grocery_Item> shopping_list;
    shopping_list.push_back(Apple);
    shopping_list.push_back(Apple);
    shopping_list.push_back(Milk);
    shopping_list.push_back(Orange);

    int Helicopter {1000};
    shopping_list.push_back(Grocery_Item(Helicopter));
    shopping_list.push_back(Grocery_Item(0));

    display_grocery_list(shopping_list);
}

enum State{Engine_Failure, Inclement_Weather, Nominal, Unknown};
enum Sequence{Abort, Hold, Launch};

std::istream &operator>>(std::istream &is, State &state)
{
    std::underlying_type_t<State> user_input;
    is >> user_input;

    switch (user_input)
    {
    case Engine_Failure:
    case Inclement_Weather:
    case Nominal:
    case Unknown:
        state = State(user_input);
        break;
    default:
        std::cout << "User input is not a valid launch state." << std::endl;
        break;
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Sequence &sequence)
{
	switch (sequence) {
	    case Abort:    
            os << "Abort"; 
            break;
		case Hold:      
            os << "Hold"; 
            break;
		case Launch:    
            os << "Launch"; 
            break;
    }
	
	return os;
}

void initiate(Sequence sequence)
{
	std::cout << "Initiate " << sequence << " sequence!" << std::endl;   // Uses overloaded operator<<
}

void test3()
{
    std::cout << "\n Test3 =========================" << std::endl;
    State state;
	std::cout << "Launch state: ";
	std::cin >> state;               // users the overloaded operator>>
	
	switch (state) {
		case Engine_Failure:        // Abort if Engine Failure
        case Unknown:               // or Unknown!
            initiate(Abort); 
            break;
		case Inclement_Weather:    
            initiate(Hold); 
            break;
		case Nominal:              
            initiate(Launch); 
            break;
	}    
}


int main()
{
    // test1();
    // test2();
    test3();
    std::cout << std::endl;
    return 0;
}
