#include<iostream>
#include<string>
#include<limits>
#include<iomanip>
#include<climits>


enum Genre { FICTION, NONFICTION, SCIENCE, HISTORY, TECHNOLOGY};

// Sepcial function to return the string of the genre
std::string get_genre_names(Genre G){
    if(G == Genre::FICTION) return "Fiction";
    else if(G == Genre::NONFICTION) return "NonFiction";
    else if(G == Genre::HISTORY) return "History";
    else if(G == Genre::SCIENCE) return "Science";
    else if(G == Genre::TECHNOLOGY) return "Technology";
    else return "";
}

class Book{
    private:
        int bookID;
        float rating;
        double price;
        char availabilityStatus; //('A' for Available, 'B' for Borrowed)
        bool isReferenceOnly;
        std::string title;
        Genre genre;
    
        public:
            Book(){
                bookID = 0;
                rating = 0.0;
                price = 0.0;
                availabilityStatus = 'A';
                isReferenceOnly = false;
                title = "Untitled";
                genre = Genre::FICTION;
            }

            // Patrameterized constructor
            Book(int bookID,float rating,double price,char availabilityStatus,bool isReferenceOnly,std::string title, Genre genre):bookID(bookID),
            rating(rating),
            price(price),
            availabilityStatus(availabilityStatus),
            isReferenceOnly(isReferenceOnly),
            title(title),
            genre(genre) {}

            ~Book(){
                std::cout<<"Book object with ID "<<bookID<<"Destroyed"<<std::endl;
            }
            
            //Getters 
            int getBookID() const{
                return bookID;
            }
            float getRating() const{
                return rating;
            }
            double getPrice() const{
                return price;
            }
            char getAvailabilityStatus() const{
                return availabilityStatus;
            }
            bool getIsReferenceOnly() const{
                return isReferenceOnly;
            }
            std::string getTitle()const{
                return title;
            }
            Genre getGenre()const{
                return genre;
            }

            //Setters
            void setBookID(int bookID){
                this->bookID = bookID;
            }
            void setRating(float rating){
                this->rating = rating;
            }
            void setPrice(double price){
                this->price = price;
            }
            void setAvailabilityStatus(char availabilityStatus){
                this->availabilityStatus = availabilityStatus;
            }
            void setIsReferenceOnly(bool isReferenceOnly){
                this->isReferenceOnly = isReferenceOnly;
            }
            void setTitle(std::string title){
                this->title = title;
            }
            void setGenre(Genre genre){
                this->genre = genre;
            }

            // Member function : update availability
            void updateAvailability(bool isBorrowed){
                availabilityStatus = isBorrowed ? 'B' : 'A';
            }

            void displayDetails() const{

                std::string avl_status = (availabilityStatus == 'A') ? "Available" : "Borrowed";
                std::string is_for_reference = (isReferenceOnly) ? "Yes" : "No" ; 

                std::cout<<"\n * * * * * * * * * * * * * * * Book Details * * * * * * * * * * * * * * * "<<std::endl;
                std::cout<<"Book ID: "<<std::to_string(bookID)<<std::endl;
                std::cout<<"Rating: "<<std::to_string(rating)<<std::endl;
                std::cout<<"Price: "<<std::to_string(price)<<std::endl;
                std::cout<<"Availability Status: "<<avl_status<<std::endl;
                std::cout<<"Is for Reference only: "<<is_for_reference<<std::endl;
                std::cout<<"Title: "<<title<<std::endl;
                std::cout<<"Genre: "<<get_genre_names(genre)<<std::endl;
                std::cout<<" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * "<<std::endl;
            }
};

void markAsReference(Book &book){
    std::string previous_marking = (book.getIsReferenceOnly()) ? "Yes":"No";
    book.setIsReferenceOnly(1);
    std::cout<<"Previous Marking: "<<previous_marking<<std::endl;
    std::cout<<"New Marking: "<< ((book.getIsReferenceOnly()) ? "Yes":"No" )<<std::endl;
    std::cout<<"Book marked as reference successfully...."<<std::endl;
}

bool isAffordable(const Book &book, const double budget){
    return book.getPrice() <= budget;
}

void printFormattedBookList(Book books[], int size) {
    // Print header
    std::cout << std::left << std::setw(8) << "ID"
         << std::left << std::setw(20) << "Title"
         << std::right << std::setw(10) << "Price"
         << std::right << std::setw(10) << "Rating"
         << std::left << std::setw(15) << "Status"
         << std::left << std::setw(15) << "Reference" 
         << std::endl;

    std::cout << std::string(78, '-') << std::endl; 

    // Print each book
    for (int i = 0; i < size; i++) {
        std::string avl = (books[i].getAvailabilityStatus()=='A') ? "Available" : "Not Available";
        std::string is_only_ref = (books[i].getIsReferenceOnly()) ? "Only Reference" : "Can be used";

        std::cout << std::left << std::setw(8)  << books[i].getBookID()
             << std::left << std::setw(20) << books[i].getTitle()
             << std::right << std::setw(10) << books[i].getPrice()
             << std::right << std::setw(10) << books[i].getRating()
             << std::left << std::setw(15) << avl
             << std::left << std::setw(15) << is_only_ref
             << std::endl;
    }
}

template <typename T>
T getValidatedVal(const std::string& str, T minVal, T maxVal) {
    T res;
    while (true) {
        std::cout << str << std::endl;
        std::cin >> res;
        if (res >= minVal && res <= maxVal) break;
        std::cout << "Criteria not satisfied .. Enter no between "
                  << minVal << " and " << maxVal << std::endl;
    }
    return res;
}
std::string getValidatedtitle(const std::string& str){
    std::string res;
    while(true){
        std::cout << str << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::getline(std::cin, res);

        if(!res.empty()) return res;
        std::cout << "Invalid input... reenter values..." << std::endl;
    }
}
// Checking if book is registered or not
Book* book_exists(Book books[], int totalBooks, int id){
    for(int i=0;i<totalBooks;i++){
        if(books[i].getBookID() == id) return &books[i];
    }
    return nullptr;
}

int main(){

    int choice;// for switch case statement below
    // Books object intialization
    Book books[10];
    Book book1(101, 4.5, 299.99, 'A', false, "C++ Primer", TECHNOLOGY);
    Book book2(102, 3.8, 150.00, 'B', true, "Design Patterns", SCIENCE);
    Book book3;
    int bookCount = 3;
    books[0] = book1;
    books[1] = book2;
    books[2] = book3;

    std::cout<<" * * * * * * * * * * * * * * * * * Welcome to Library Mangament System * * * * * * * * * * * * * * * * * "<<std::endl;

    while (true)
    {
        std::cout<<"1. Add book details: "<<std::endl;
        std::cout<<"2. Mark a book as reference-only: "<<std::endl;
        std::cout<<"3. Check if book affordable: "<<std::endl;
        std::cout<<"4. Update availability: "<<std::endl;
        std::cout<<"5. Display book details: "<<std::endl;
        std::cout<<"6. Display all books in formatted list: "<<std::endl;
        std::cout<<"7. Exit: "<<std::endl;
        std::cout<<"Enter your choice: "<<std::endl;
        std::cin>>choice;

        switch (choice)
        {
        case 1:{
            int bookID;
            float rating;
            double price;
            char availabilityStatus;
            bool isReferenceOnly;
            std::string title;
            Genre genre;
            
            std::cout<<"Enter the id of the book: "<<std::endl;
            std::cin>>bookID;
            
            rating = getValidatedVal("Enter Rating: ",0.0,5.0); // template for validation
            
            price = getValidatedVal("Enter the price of book: ",0,INT_MAX);// template for validatio
            
            std::cout<<"Enter availability status: ('A','B')"<<std::endl;
            std::cin>>availabilityStatus;

            std::cout<<"Enter i it for reference only : (1,0)"<<std::endl;
            std::cin>>isReferenceOnly;
            
            title = getValidatedtitle("Enter the title of the book: ");

            genre = static_cast<Genre>(getValidatedVal<int>("Enter the Genre Value: (0: Fictional, 1: Non fictional, 2: History, 3: Science, 4: Technology)",0,4));

            books[++bookCount] = { bookID, rating, price, availabilityStatus, 
                       isReferenceOnly, title, genre };
            std::cout<<"New book added successfully..."<<std::endl;
            break;
        }

        case 2:{
            int id;
            std::cout<<"Enter the id of book to mark reference: "<<std::endl;
            std::cin>>id;
            Book* bookFound = book_exists(books,bookCount, id);
            if(bookFound != nullptr){
                markAsReference(*bookFound);
            }
            else{
                std::cout<<"Book Not found.."<<std::endl;
            }
            break;
        }
        
        case 3:{
            int id;
            double price;
            std::cout<<"Enter the id of book to check is affordable or not: "<<std::endl;
            std::cout<<"Enter your budget: "<<std::endl;
            std::cin>>id;
            std::cin>>price;
            Book* bookFound = book_exists(books,bookCount, id);
            if(bookFound != nullptr){
                if(isAffordable(*bookFound,price)){
                    std::cout<<"Book is Affordable..."<<std::endl;
                }
                else{
                    std::cout<<"Book is Not Affordable..."<<std::endl;
                }
            }
            else{
                std::cout<<"Book Not found.."<<std::endl;
            }
            break;
        }

        case 4:{
            int id;
            char new_availability;
            std::cout<<"Enter the id of book to update availability: "<<std::endl;
            std::cin>>id;
            std::cout<<"Enter the new availability: ('A','B')"<<std::endl;
            std::cin>>new_availability;
            Book* bookFound = book_exists(books,bookCount, id);
            if(bookFound != nullptr){
                bookFound->setAvailabilityStatus(new_availability);
                std::cout<<"Status updated Successfully.."<<std::endl;
            }
            else{
                std::cout<<"Book Not found.."<<std::endl;
            }
            break;
        }

        case 5:{
            int id;
            std::cout<<"Enter the id of book to display book details: "<<std::endl;
            std::cin>>id;
            Book* bookFound = book_exists(books,bookCount, id);
            if(bookFound != nullptr){
                bookFound->displayDetails();
            }
            else{
                std::cout<<"Book Not found.."<<std::endl;
            }
            break;
        }
        
        case 6:
            printFormattedBookList(books, bookCount);
            break;

        case 7:
            std::cout<<"Thank you for using the application..."<<std::endl;
            return 0;

        default:
            std::cout<<"Invalid argument.."<<std::endl;
            break;
        }

    }
}