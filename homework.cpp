#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std; // namespace std 사용

class Book
{
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {}
};

class BorrowManager
{
    // 작가 - 책 - 재고 
    unordered_map<string, int> stock;
    
public:
    void initializeStock(Book book, int quantity = 3)
    {
        stock[book.title] = quantity;
    }

    void borrowBook(const string& title)
    {
        if (stock.find(title) == stock.end() || stock[title] == 0)
        {
            cout << "책이 모두 대여 중이거나 등록되지 않았습니다." << '\n';
            return;
        }
        
        cout << "책이 대여되었습니다. " << endl;
        stock[title]--;
    }

    void returnBook(const string& title)
    {
        if (stock.find(title) == stock.end() || stock[title] == 3)
        {
            cout << "도서관에 등록되어 있지 않은 책입니다." << '\n';
            return;
        }
        
        cout << "책이 반납되었습니다. " << endl;
        stock[title]++;
    }

    void displayStock() const
    {
        for (auto it = stock.begin(); it != stock.end(); it++)
        {
            cout << "책 제목: " <<  it->first << '\t' << "재고: " << it->second << '\n';
        }
    }
};

class BookManager
{
private:
    vector<Book> books; // 책 목록 저장

    // 책 제목으로 검색
    Book* findBookByTitle(const string& title) 
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].title == title)
                return &books[i];
        }
        return nullptr;
    }

    // 책 작가로 검색
    Book* findBookByAuthor(const string& author) 
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].author == author)
                return &books[i];
        }
        return nullptr;
    }

public:
    // 책 추가 메서드
    void addBook(const string& title, const string& author)
    {
        books.push_back(Book(title, author)); // push_back 사용
        cout << "책이 추가되었습니다: " << title << " by " << author << endl;
    }

    // 모든 책 출력 메서드
    void displayAllBooks() const
    {
        if (books.empty())
        {
            cout << "현재 등록된 책이 없습니다." << endl;
            return;
        }

        cout << "현재 도서 목록:" << endl;
        for (size_t i = 0; i < books.size(); i++)
        { // 일반적인 for문 사용
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }

    Book* getBookByTitle(const string& title)
    {
        return findBookByTitle(title);
    }

    Book* getBookByAuthor(const string& author)
    {
        return findBookByAuthor(author);
    }
};

int main()
{
    BookManager bookManager;
    BorrowManager borrowManager;
    
    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
    while (true)
    {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl; // 책 정보를 입력받아 책 목록에 추가
        cout << "2. 모든 책 출력" << endl; // 현재 책 목록에 있는 모든 책 출력
        cout << "3. 책 대여" << endl; // 책 대여
        cout << "4. 책 반납" << endl; // 책 반납 
        cout << "5. 프로그램 종료" << endl; // 프로그램 종료
        cout << "선택: ";

        int choice; // 사용자의 메뉴 선택을 저장
        cin >> choice;

        if (choice == 1)
        {
            // 1번 선택: 책 추가
            // 사용자로부터 책 제목과 저자명을 입력받아 BookManager에 추가합니다.
            string title, author;
            cout << "책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title); // 제목 입력 (공백 포함)
            cout << "책 저자: ";
            getline(cin, author); // 저자명 입력 (공백 포함)
            bookManager.addBook(title, author); // 입력받은 책 정보를 추가
            borrowManager.initializeStock({title, author});
        }
        else if (choice == 2)
        {
            // 2번 선택: 모든 책 출력
            // 현재 BookManager에 저장된 책 목록을 출력합니다.
            bookManager.displayAllBooks();
        }
        else if (choice == 3)
        {
            // 3번 선택: 책의 대여 여부 확인
            cout << "[책 대여]" << endl;
            cout << "-책 리스트" << endl;
            
            borrowManager.displayStock();
            
            cout << endl;
            cout << "1. 책 이름으로 찾기 \t 2. 작가 이름으로 찾기" << endl;
            
            int choice;
            cin >> choice;
            cin.ignore();
            if (choice == 1)
            {
                // 책 제목으로 대여
                cout << "책 이름을 입력하세요." << endl;
                string bookName;
                getline(cin, bookName);
                borrowManager.borrowBook(bookName);
            }
            else if (choice == 2)
            {
                // 작가 이름으로 대여
                cout << "작가 이름을 입력하세요." << endl;
                string authorName;
                getline(cin, authorName);
                Book* book = bookManager.getBookByAuthor(authorName);
                if (book != nullptr)
                    borrowManager.borrowBook(book->title);
                else
                    cout << "잘못된 접근입니다. " << endl;
            }
            else
            {
                cout << "잘못된 입력입니다." << endl;
            }
        }
        else if (choice == 4)
        {
            // 4번 선택: 책의 대여 여부 확인
            cout << "[책 반납]" << endl;
            cout << "-책 리스트" << endl;
            
            borrowManager.displayStock();

            cout << "1. 책 이름으로 반납 \t 2. 책 작가로 반납" << endl; 
            
            int choice;
            cin >> choice;
            cin.ignore();

            if (choice == 1)
            {
                cout << "반납할 책 제목을 입력하세요. " << endl;
            
                // 책 제목으로 반납
                string bookName;
                getline(cin, bookName);
                borrowManager.returnBook(bookName);
            }
            else if (choice == 2)
            {
                cout << "반납할 책의 작가 이름을 입력하세요. " << endl;

                // 책 작가로 반납
                string authorName;
                getline(cin, authorName);
                Book* book = bookManager.getBookByAuthor(authorName);
                if (book != nullptr)
                    borrowManager.returnBook(book->title);
                else
                    cout << "잘못된 접근입니다. " << endl;
            }
            else
            {
                cout << "잘못된 입력입니다." << endl;
            }
        }
        else if (choice == 5)
        {
            // 5번 선택: 종료
            // 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
            cout << "프로그램을 종료합니다." << endl;
            break; // while 루프 종료
        }
        else
        {
            // 잘못된 입력 처리
            // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0; // 프로그램 정상 종료
}