#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Product {
protected:
    string brand;
    string name;
    double price;
    int year;

public:
    virtual ~Product() {}

    Product(const string& brand, const string& name, double price, int year) {
        this->brand = brand;
        this->name = name;
        this->price = price;
        this->year = year;
    }

    string getBrand() const {
        return brand;
    }

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    int getYear() const {
        return year;
    }

    virtual void printBicycle() const {
        cout << "Brand: " << brand << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << "$" << endl;
        cout << "Year: " << year << endl;
    }
};

class Bicycle : public Product {
private:
    double wheel;
    double weight;
    string color;

public:
    virtual ~Bicycle() {}

    Bicycle(const string& brand, const string& name, double wheel, double weight, const string& color, double price, int year) : Product(brand, name, price, year) {
        this->brand = brand;
        this->name = name;
        this->wheel = wheel;
        this->weight = weight;
        this->color = color;
        this->price = price;
        this->year = year;
    }

    double getWheel() const {
        return wheel;
    }

    double getWeight() const {
        return weight;
    }

    string getColor() const {
        return color;
    }

    virtual void printBicycle() const {
        Product::printBicycle();
        cout << "Wheel size: " << wheel << endl;
        cout << "Weight: " << weight << "kg" << endl;
        cout << "Color: " << color << endl;
    }
};

class Person {
private:
    string name;
    string surname;
    int age;
public:
    virtual ~Person() {}
    
    Person(const string name, const string surname, const int age) {
        this->name = name;
        this->surname = surname;
        this->age = age;
    }

    string getName() const {
        return name;
    }

    string getSurname() const {
        return surname;
    }

    int getAge() const {
        return age;
    }

    virtual void printPerson() const {
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Age: " << age << endl;
    }
};

class Buyer : public Person {
private:
    string product;
    double budget;
public:
    virtual ~Buyer() {}

    Buyer(const string name, const string surname, const int age, const string product, const double budget) : Person(name, surname, age) {
        this->product = product;
        this->budget = budget;
    }

    string getProduct() const {
        return product;
    }

    double getBudget() const {
        return budget;
    }

    virtual void printBuyer() const {
        printPerson();
        cout << "Product: " << product << endl;
        cout << "Budget: " << budget << endl;
    }
};

class Employee : public Person {
private:
    string post;
    string store;
    double salary;
public:
    virtual ~Employee() {}

    Employee(const string name, const string surname, const int age, const string post, const string store, const double salary) : Person(name, surname, age) {
        this->post = post;
        this->store = store;
        this->salary = salary;
    }
    
    string getPost() const {
        return post;
    }

    string getStore() const {
        return store;
    }

    double getSalary() const {
        return salary;
    }

    virtual void printEmployee() const {
        printPerson();
        cout << "Post: " << post << endl;
        cout << "Store: " << store << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Review {
private:
    const Bicycle* bicycle;
    const Buyer* buyer;
    double rating;
    string text;
public:

    virtual ~Review() {}

    Review(const Bicycle& bicycle, const Buyer& buyer, double rating, const string& text) {
        this->bicycle = &bicycle;
        this->buyer = &buyer;
        this->rating = rating;
        this->text = text;
    }

    const Bicycle* getProduct() const {
        return bicycle;
    }

    const Buyer* getBuyer() const {
        return buyer;
    }

    double getRating() const {
        return rating;
    }

    string getText() const {
        return text;
    }
};

void addBicycle(vector<Bicycle>& bicycles) {
    string brand, name, color;
    double wheel, weight, price;
    int year;

    cout << "Enter bicycle details:\n" << endl;
    cout << "Brand: ";
    cin >> brand;
    cout << "Name: ";
    cin >> name;
    cout << "Wheel size: ";
    cin >> wheel;
    cout << "Weight: ";
    cin >> weight;
    cout << "Color: ";
    cin >> color;
    cout << "Price: ";
    cin >> price;
    cout << "Year: ";
    cin >> year;

    bicycles.emplace_back(brand, name, wheel, weight, color, price, year);
}

static void addBuyer(vector<Buyer>& buyers) {
    string name, surname, product;
    int age;
    double budget;

    cout << "Enter buyer details:\n" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Surname: ";
    cin >> surname;
    cout << "Age: ";
    cin >> age;
    cout << "Product: ";
    cin.ignore();
    getline(cin, product);
    cout << "Budget: ";
    cin >> budget;

    buyers.emplace_back(name, surname, age, product, budget);
}

void addEmployee(vector<Employee>& employees) {
    string name, surname, post, store;
    int age;
    double salary;

    cout << "Enter employee details:\n" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Surname: ";
    cin >> surname;
    cout << "Age: ";
    cin >> age;
    cout << "Post: ";
    cin >> post;
    cout << "Store: ";
    cin >> store;
    cout << "Salary: ";
    cin >> salary;

    employees.emplace_back(name, surname, age, post, store, salary);
}

void bicycleDetalis(const vector<Bicycle> bicycles) {
    cout << "Bicycles Details:\n" << endl;

    for (const auto& bicycle : bicycles) {
        bicycle.printBicycle();
        cout << endl;
    }
}

void buyesDetails(const vector<Buyer> buyers) {
    cout << "Buyer Details:\n" << endl;

    for (const auto& buyer : buyers) {
        buyer.printBuyer();
        cout << endl;
    }
}

void employeesDetails(const vector<Employee> employees) {
    cout << "\nEmployee Details:\n" << endl;

    for (const auto& employee : employees) {
        employee.printEmployee();
        cout << endl;
    }
}

void reviewsDetails(const vector<Review>& reviews) {
    cout << "Reviews Details:\n" << endl;

    for (const auto& review : reviews) {
        cout << "Product: " << review.getProduct()->getName() << " by " << review.getProduct()->getBrand() << endl;
        cout << "Buyer: " << review.getBuyer()->getName() << " " << review.getBuyer()->getSurname() << endl;
        cout << "Rating: " << review.getRating() << endl;
        cout << "Review Text: " << review.getText() << endl;
        cout << endl;
    }
}

void modifyBicycle(vector<Bicycle>& bicycles) {
    int index;
    cout << "Enter the index of the bicycle to modify: ";
    cin >> index;

    if (index >= 0 && index < bicycles.size()) {
        string brand, name, color;
        double wheel, weight, price;
        int year;

        cout << "Enter new details for the bicycle:\n" << endl;
        cout << "Brand: ";
        cin >> brand;
        cout << "Name: ";
        cin >> name;
        cout << "Wheel size: ";
        cin >> wheel;
        cout << "Weight: ";
        cin >> weight;
        cout << "Color: ";
        cin >> color;
        cout << "Price: ";
        cin >> price;
        cout << "Year: ";
        cin >> year;

        bicycles[index] = Bicycle(brand, name, wheel, weight, color, price, year);
        cout << "\nBicycle modified successfully.\n" << endl;
    }
    else cout << "\nInvalid index.\n" << endl;
}

void modifyBuyer(vector<Buyer>& buyers) {
    int index;
    cout << "Enter the index of the buyer to modify: ";
    cin >> index;

    if (index >= 0 && index < buyers.size()) {
        string name, surname, product;
        int age;
        double budget;

        cout << "Enter new details for the buyer:\n" << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Surname: ";
        cin >> surname;
        cout << "Age: ";
        cin >> age;
        cout << "Product: ";
        cin.ignore();
        getline(cin, product);
        cout << "Budget: ";
        cin >> budget;

        buyers[index] = Buyer(name, surname, age, product, budget);
        cout << "\nBuyer modified successfully.\n" << endl;
    }
    else cout << "\nInvalid index.\n" << endl;
}

void modifyEmployee(vector<Employee>& employees) {
    int index;
    cout << "Enter the index of the employee to modify: ";
    cin >> index;

    if (index >= 0 && index < employees.size()) {
        string name, surname, post, store;
        int age;
        double salary;

        cout << "Enter new details for the employee:\n" << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Surname: ";
        cin >> surname;
        cout << "Age: ";
        cin >> age;
        cout << "Post: ";
        cin >> post;
        cout << "Store: ";
        cin >> store;
        cout << "Salary: ";
        cin >> salary;

        employees[index] = Employee(name, surname, age, post, store, salary);
        cout << "\nEmployee modified successfully.\n" << endl;
    }
    else cout << "\nInvalid index.\n" << endl;
}

void modifyReview(vector<Review>& reviews, const vector<Bicycle>& bicycles, const vector<Buyer>& buyers) {
    int index;
    cout << "Enter the index of the review to modify: ";
    cin >> index;

    if (index >= 0 && index < reviews.size()) {
        string productName, buyerName, buyerSurname, reviewText;
        double rating;

        cout << "Enter new details for the review:\n" << endl;
        cout << "Product Name: ";
        cin >> productName;
        cout << "Buyer Name: ";
        cin >> buyerName;
        cout << "Buyer Surname: ";
        cin >> buyerSurname;
        cout << "Rating (from 1 to 10): ";
        cin >> rating;
        cout << "Review Text: ";
        cin.ignore();
        getline(cin, reviewText);

        const Bicycle* productPtr = nullptr;
        const Buyer* buyerPtr = nullptr;

        for (const auto& bicycle : bicycles) {
            if (bicycle.getName() == productName) {
                productPtr = &bicycle;
                break;
            }
        }

        for (const auto& buyer : buyers) {
            if (buyer.getName() == buyerName && buyer.getSurname() == buyerSurname) {
                buyerPtr = &buyer;
                break;
            }
        }

        if (productPtr != nullptr && buyerPtr != nullptr) {
            reviews[index] = Review(*productPtr, *buyerPtr, rating, reviewText);
            cout << "Review modified successfully.\n" << endl;
        }
        else cout << "\nError: Product or buyer not found. Review not modified.\n" << endl;
    }
    else cout << "\nInvalid index.\n" << endl;
}

void removeBicycle(vector<Bicycle>& bicycles) {
    int index;
    cout << "Enter the index of the bicycle to remove: ";
    cin >> index;

    if (index >= 0 && index < bicycles.size()) {
        bicycles.erase(bicycles.begin() + index);
        cout << "Bicycle removed successfully.\n" << endl;
    }
    else cout << "\nInvalid index.\n" << endl;
}

void removeBuyer(vector<Buyer>& buyers) {
    int index;
    cout << "Enter the index of the buyer to remove: ";
    cin >> index;

    if (index >= 0 && index < buyers.size()) {
        buyers.erase(buyers.begin() + index);
        cout << "Buyer removed successfully.\n" << endl;
    }
    else cout << "\nInvalid index.\n" << endl;
}

void removeEmployee(vector<Employee>& employees) {
    int index;
    cout << "Enter the index of the employee to remove: ";
    cin >> index;

    if (index >= 0 && index < employees.size()) {
        employees.erase(employees.begin() + index);
        cout << "Employee removed successfully.\n" << endl;
    }
    else cout << "\nInvalid index.\n" << endl;
}

void removeReview(vector<Review>& reviews) {
    int index;
    cout << "Enter the index of the review to remove: ";
    cin >> index;

    if (index >= 0 && index < reviews.size()) {
        reviews.erase(reviews.begin() + index);
        cout << "Review removed successfully.\n" << endl;
    }
    else {
        cout << "\nInvalid index.\n" << endl;
    }
}

void addElements(vector<Buyer> buyers, vector<Employee> employees, vector<Bicycle> bicycles, vector<Review> reviews) {
    while (true) {
        int a;
        cout << "1. Hire an Employee" << endl;
        cout << "2. Add new Buyer" << endl;
        cout << "3. Order a Bicycle" << endl;
        cout << "4. Add new Reviews" << endl;
        cout << "0. Back\n" << endl;
        cin >> a;
        switch (a) {
        case 1:
            addEmployee(employees);
            break;
        case 2:
            addBuyer(buyers);
            break;
        case 3:
            addBicycle(bicycles);
            break;
        case 4:
            
            break;
        case 0:
            cout << "\nReturn to Main Menu...\n" << endl;
            return;;
        default:
            cout << "\nInvalid choice.\n" << endl;
            break;
        }
    }
}

void editElements(vector<Buyer> buyers, vector<Employee> employees, vector<Bicycle> bicycles, vector<Review> reviews) {
    while (true) {
        int a;
        cout << "1. Edit Employee's info" << endl;
        cout << "2. Edit Buyer's info" << endl;
        cout << "3. Edit Bicycle's info" << endl;
        cout << "4. Edit Review" << endl;
        cout << "0. Back\n" << endl;
        cin >> a;
        switch (a) {
        case 1:
            modifyEmployee(employees);
            break;
        case 2:
            modifyBuyer(buyers);
            break;
        case 3:
            modifyBicycle(bicycles);
            break;
        case 4:
            modifyReview(reviews, bicycles, buyers);
            break;
        case 0:
            cout << "\nReturn to Main Menu...\n" << endl;
            return;
        default:
            cout << "\nInvalid choice.\n" << endl;
            break;
        }
    }
}

void removeElements(vector<Buyer> buyers, vector<Employee> employees, vector<Bicycle> bicycles, vector<Review> reviews) {
    while (true) {
        int a;
        cout << "1. Fire Employee" << endl;
        cout << "2. Delete Buyer" << endl;
        cout << "3. Sale Bicycle" << endl;
        cout << "4. Delete Review" << endl;
        cout << "0. Back\n" << endl;
        cin >> a;
        switch (a) {
        case 1:
            removeEmployee(employees);
            break;
        case 2:
            removeBuyer(buyers);
            break;
        case 3:
            removeBicycle(bicycles);
            break;
        case 4:
            removeReview(reviews);
            break;
        case 0:
            cout << "\nReturn to Main Menu...\n" << endl;
            return;
        default:
            cout << "\nInvalid choice.\n" << endl;
            break;
        }
    }
}

void searchElements(const vector<Buyer>& buyers, const vector<Employee>& employees, const vector<Bicycle>& bicycles) {
    int choice;
    cout << "1. Find an Employee" << endl;
    cout << "2. Find a Buyer" << endl;
    cout << "3. Find a Bicycle" << endl;
    cout << "0. Back\n" << endl;
    cin >> choice;
    bool find = false;
    switch (choice) {
    case 1: {
        string searchTerm;
        cout << "\nEnter the employee's name to search for: ";
        cin >> searchTerm;

        cout << "\nMatching employees:\n" << endl;
        for (const auto& employee : employees) {
            if (employee.getName() == searchTerm) {
                employee.printEmployee();
                cout << endl;
                find = true;
                break;
            }
        }
        if (!find) {
            cout << "\nNo matching employees.\n" << endl;
        }
        break;
    }
    case 2: {
        string searchTerm;
        cout << "\nEnter the buyer's surname to search for: ";
        cin >> searchTerm;

        cout << "\nMatching buyers:\n" << endl;
        for (const auto& buyer : buyers) {
            if (buyer.getSurname() == searchTerm) {
                buyer.printBuyer();
                cout << endl;
                find = true;
                break;
            }
        }
        if (!find) {
            cout << "\nNo matching buyers.\n" << endl;
        }
        break;
    }
    case 3: {
        string searchTerm;
        cout << "\nEnter the bicycle's brand to search for: ";
        cin >> searchTerm;

        cout << "\nMatching bicycles:\n" << endl;
        for (const auto& bicycle : bicycles) {
            if (bicycle.getBrand() == searchTerm) {
                bicycle.printBicycle();
                cout << endl;
                find = true;
                break;
            }
        }
        if (!find) {
            cout << "\nNo matching bicycles.\n" << endl;
        }
        break;
    }
    case 0:
        cout << "\nReturn to Main Menu...\n" << endl;
        return;
    default:
        cout << "\nInvalid choice.\n" << endl;
        break;
    }
}

double calculateAverageRating(const vector<Review>& reviews) {
    if (reviews.empty()) {
        cout << "No reviews available." << endl;
        return 0.0;
    }

    double totalRating = 0.0;
    for (const auto& review : reviews) {
        totalRating += review.getRating();
    }
    return totalRating / reviews.size();
}

double totalBudget(const vector<Buyer>& buyers) {
    double total = 0.0;

    for (const auto& buyer : buyers) {
        total += buyer.getBudget();
    }
    return total;
}

void printBuyersByProduct(const string& product, const vector<Buyer>& buyers, const vector<Review>& reviews) {
    bool found = false;

    cout << "Buyers of " << product << ":\n" << endl;

    for (const auto& buyer : buyers) {
        if (buyer.getProduct() == product) {
            buyer.printBuyer();
            for (const auto& review : reviews) {
                if (review.getProduct()->getName() == product && review.getBuyer()->getName() == buyer.getName()) {
                    cout << "Review: " << review.getText() << endl;
                    break;
                }
            }
            cout << endl;
            found = true;
        }
    }
    if (!found) cout << "No buyers found for " << product << endl;
}

void interface(vector<Buyer> buyers, vector<Employee> employees, vector<Bicycle> bicycles, vector<Review> reviews) {
    while (true) {
        int a;

        cout << "\nChoose the Function:\n" << endl;
        cout << "1. Show a summary of the Store" << endl;
        cout << "2. Add info to the Store" << endl;
        cout << "3. Delete store Element" << endl;
        cout << "4. Edit Sore info" << endl;
        cout << "5. Search in Store" << endl;
        cout << "0. Exit\n" << endl;
        cin >> a;

        switch (a) {
        case 1:
            employeesDetails(employees);
            buyesDetails(buyers);
            cout << "Total budget of all buyers: " << totalBudget(buyers) << "$\n" << endl;
            bicycleDetalis(bicycles);
            printBuyersByProduct("Mountain Bike", buyers, reviews);
            reviewsDetails(reviews);
            cout << "Average bicycle rating: " << calculateAverageRating(reviews) << endl;
            break;
        case 2:
            addElements(buyers, employees, bicycles, reviews);
            break;
        case 3:
            removeElements(buyers, employees, bicycles, reviews);
            break;
        case 4:
            editElements(buyers, employees, bicycles, reviews);
            break;
        case 5:
            searchElements(buyers, employees, bicycles);
            break;
        case 0:
            cout << "\nGoodbye!\n" << endl;
            return;
        default:
            cout << "\nInvalid choice.\n" << endl;
            break;
        }
    }
}

int main(int argc, const char* argv[]) {
    cout << "Wellcome to the BiStore!" << endl;

    vector<Buyer> buyers = {
        Buyer("Alice", "Smith", 25, "Bicycle Red", 1000),
        Buyer("Bob", "Johnson", 40, "Mountain Bike", 2000)
    };

    vector<Employee> employees = {
        Employee("John", "Doe", 30, "Manager", "Alt Store", 50000),
        Employee("Maria", "Romanova", 27, "Cashier", "Center Store", 18000)
    };

    vector<Bicycle> bicycles = {
        Bicycle("Stels", "Quantum", 20, 7, "Blue", 550, 2024),
        Bicycle("Dew", "Mountain Bike", 23, 4.5, "Yellow", 690, 2023)
    };

    vector<Review> reviews = {
        Review (bicycles[0], buyers[0], 8.5, "Great bicycle, smooth ride!"),
        Review (bicycles[0], buyers[1], 9.0, "Excellent bike, sturdy build!"),
        Review (bicycles[1], buyers[1], 9.2, "Fantastic bike for off-road adventures!")
    };

    interface(buyers, employees, bicycles, reviews);
    return 0;
}
 
