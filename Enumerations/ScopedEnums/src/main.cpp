#include <iostream>
#include <vector>

//Used for test1
//Scoped enumeration holding the items for a grocery list
// The value of the enumerator could be the item code
enum class Grocery_Item {Milk = 350, Bread = 250, Apple = 132, Orange = 100};

std::ostream &operator<<(std::ostream &os, Grocery_Item grocery_Item)
{
    std::underlying_type_t<Grocery_Item> value = std::underlying_type_t<Grocery_Item>(grocery_Item);
    switch (grocery_Item)
    {
    case Grocery_Item::Milk:
        os << "Milk";
    case Grocery_Item::Bread:
        os << "Bread";
        break;
    case Grocery_Item::Apple:
        os << "Apple";
        break;
    case Grocery_Item::Orange:
        os << "Orange";
        break;
    default:
        os << "Invalid item";
        break;
    }
    return os;
}

// Used for test1
// Returns a boolean depending on whether the Grocery_Item
// paramter is a valid enumerator or not
bool is_valid_grocery_item(Grocery_Item grocery_Item)
{
    switch (grocery_Item)
    {
    case Grocery_Item::Milk:
    case Grocery_Item::Bread:
    case Grocery_Item::Apple:
    case Grocery_Item::Orange:
        return true;
    default:
        return false;
    }
}

// Used for test1
// Display the grocery items in the grocery list
// Gicen a vector of Grocery_Items, this function displays
// the string representation of each item using the overloaded
// operator<< function
// This function also keeps track of how many valid and invalid items
// are in the provided vector by using the is_valid_grocery_item function
// written above
void display_grocery_list(const std::vector<Grocery_Item> &grocery_List)
{
    std::cout << "Grocery List" << "\n ===================" << std::endl;
    int invalid_item_count{0};
    int valid_item_count{0};
    for(Grocery_Item grocery_Item: grocery_List)
    {
        std::cout << grocery_Item << std::endl;
        if(is_valid_grocery_item(grocery_Item))
            valid_item_count++;
        else
            invalid_item_count++;
    }
    std::cout << "===================" << std::endl;
    std::cout << "Valid items:" << valid_item_count << std::endl;
    std::cout << "Invalid items:" << invalid_item_count << std::endl;
    std::cout << "Total items:" << valid_item_count + invalid_item_count << std::endl;
}

void test1()
{
    std::cout << "\n Test1 ===================" << std::endl;
    std::vector<Grocery_Item> shopping_list;

    shopping_list.push_back(Grocery_Item::Apple);
    shopping_list.push_back(Grocery_Item::Milk);
    shopping_list.push_back(Grocery_Item::Orange);
    
    int Helicopter {100};
    shopping_list.push_back(Grocery_Item(Helicopter));
    shopping_list.push_back(Grocery_Item(350));
    
    display_grocery_list(shopping_list);
}

// Used for test2
// A simple class that might model a Player in a game application
// The player has a name, a mode that they are currently in, and a 
// direction which they are facing.
class Player {
    friend std::ostream &operator<< (std::ostream &os, const Player &p);
public:
    enum class Mode {Attack, Defense, Idle};
    enum class Direction {North, South, East, West};

    Player(std::string name, Mode mode = Mode::Idle, Direction direction = Direction::North):
        name{name}, mode{mode}, direction{direction} {}

    std::string get_name() const{
        return name;
    }
    void set_name(std::string name){
        this->name = name;
    }
    Mode get_mode() const{
        return mode;
    }
    void set_mode(Mode mode){
        this->mode = mode;
    }
    Direction get_direction() const{
        return direction;
    }
    void set_direction(Direction direction){
        this->direction = direction;
    }
private:
    std::string name;
    Mode mode;
    Direction direction;
};

// Used for test2
// A simple function that returns the string representation
// of the Player::Mode paramter passed into it.
std::string get_player_mode(Player::Mode mode){
    std::string result;
    switch (mode){
    case Player::Mode::Attack:
        result = "Attack";
        break;
    case Player::Mode::Defense:
        result = "Defense";
        break;
    case Player::Mode::Idle:
        result = "Idle";
        break;
    default:
        result = "Unknown Mode";
        break;
    }
    return result;
}

// Used for test2
// A simple function that returns the string representation
// of the Player::Direction paramter passed into it.
std::string get_player_direction(Player::Direction direction){
    std::string result;
    switch (direction)
    {
    case Player::Direction::North:
        result = "North";
        break;
    case Player::Direction::South:
        result = "South";
        break;
    case Player::Direction::West:
        result = "West";
        break;
    case Player::Direction::East:
        result = "East";
        break;
    default:
        result = "Unknown Direction!";
        break;
    }
    return result;
}

// Used for test2
// Overloading the iutput stream insertion operator
// so we can easily put Player objects on the output stream.
std::ostream &operator<<(std::ostream &os, const Player &p){
    os << "Player name: " << p.get_name() << "\n"
       << "Player mode: " << get_player_mode(p.mode) << "\n"
       << "Player direction: " << get_player_direction(p.get_direction())
       << std::endl;
    return os;
}

void test2(){
    std::cout << "\n--- Test2 ------------------------------------\n" <<std::endl;
    Player p1{"Cloud Strife", Player::Mode::Attack, Player::Direction::North};
    Player p2{"Tifa Lockhart", Player::Mode::Defense, Player::Direction::West};
    Player p3{"Sephiroth", Player::Mode::Idle, Player::Direction::South};

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;
}

int main()
{
    // test1();
    test2();
    std::cout << "\n";
    return 0;
}
