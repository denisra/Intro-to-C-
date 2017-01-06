#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Item {
    public:
        void SetName(string nm)
            { name = nm; };
        void SetQuantity(int qnty)
            { quantity = qnty; };
		void SetPrice(int prcinDllrs)
			{ priceInDollars = prcinDllrs; };
        virtual void Print()
            { cout << name << " " << quantity << endl; };
        virtual ~Item()
            { return; };
		int GetTotalValueAsPrice()
			{ return (quantity * priceInDollars); };
    protected:
        string name;
        int    quantity;
		int	priceInDollars;
};

class Produce : public Item { // Derived from Item class
    public:
        void SetExpiration(string expir)
            { expiration = expir; };
        void Print()
            { cout << name << " x" << quantity
			  << " for " << priceInDollars
              << " (Expires: " << expiration << ")"
              << endl;
            };
    private:
        string expiration;
};

class Book : public Item {
	public:
		void SetAuthor(string authr)
			{ author = authr; };
		void Print()
		{
			cout << name << " x" << quantity
				<< " for " << priceInDollars
				<< " (Author: " << author << ")"
				<< endl;
		};
	private:
		string author;
};


class Inventory {
	public:
		void PrintInventory();
		void AddItemToInventory();
		void UpdateItemQtyInInventory();
		void RemoveItemFromInventory();	
	private:
		void SumInv();
		vector<Item*> inventory;
		int totalInvPriceDollars;
};

	// Print all items in the inventory
	void Inventory::PrintInventory() {
		unsigned int i = 0;
		if (inventory.size() == 0) {
			cout << "No items to print." << endl;
		}
		else {
			for (i = 0; i<inventory.size(); ++i) {
				cout << i << " - ";
				inventory.at(i)->Print();
			}
			cout << "Total inventory value: $" << this->totalInvPriceDollars << endl;
		}
		return;
	}

	// Dialogue to create a new item, then add that item to the inventory
	void Inventory::AddItemToInventory() {
		Produce* prdc;
		string usrInptName = "";
		string usrInptQntyStr = "";
		istringstream inSS;
		int usrInptQnty = 0;
		string usrInptExpr = "";
		int usrPrice = 0;
		string usrInpt = "";
		string usrAuthor = "";
		Book* book;

		// Get user choice
		cout << "\nAdd a book (b) or produce (p): ";
		getline(cin, usrInpt);

		if ((usrInpt.at(0) != 'b') && (usrInpt.at(0) != 'p')) {
			cout << "Invalid choice";
			return;
		}

		if (usrInpt.at(0) == 'p') {
			cout << "Enter name of new produce: ";
		}
		else {
			cout << "Enter name of new book: ";
		}

		getline(cin, usrInptName);

		cout << "Enter quantity: ";
		getline(cin, usrInptQntyStr);
		inSS.str(usrInptQntyStr);
		inSS >> usrInptQnty;
		inSS.clear();

		if (usrInpt.at(0) == 'p') {
			cout << "Enter expiration date: ";
			getline(cin, usrInptExpr);
		}
		else {
			cout << "Enter author: ";
			getline(cin, usrAuthor);
		}

		cout << "Enter the price per item: $";
		cin >> usrPrice;

		if (usrInpt.at(0) == 'p') {
			prdc = new Produce;
			prdc->SetName(usrInptName);
			prdc->SetQuantity(usrInptQnty);
			prdc->SetExpiration(usrInptExpr);
			prdc->SetPrice(usrPrice);

			this->inventory.push_back(prdc);
		}
		else {
			book = new Book;
			book->SetName(usrInptName);
			book->SetQuantity(usrInptQnty);
			book->SetAuthor(usrAuthor);
			book->SetPrice(usrPrice);

			this->inventory.push_back(book);
		}
		this->SumInv();
		return;
	}

	// Dialogue to update the quantity of an item, then update that item in the inventory
	void Inventory::UpdateItemQtyInInventory() {
		string usrIndexChoiceStr = "";
		unsigned int usrIndexChoice = 0;
		istringstream inSS;
		string usrInptQntyStr = "";
		int usrInptQnty = 0;

		if (inventory.size() == 0) {
			cout << "No items to update." << endl;
		}
		else {
			this->PrintInventory();

			do {
				cout << "Update which item #: ";
				getline(cin, usrIndexChoiceStr);
				inSS.str(usrIndexChoiceStr);
				inSS >> usrIndexChoice;
				inSS.clear();
			} while (!(usrIndexChoice < inventory.size()));

			cout << "Enter new quantity: ";
			getline(cin, usrInptQntyStr);
			inSS.str(usrInptQntyStr);
			inSS >> usrInptQnty;
			inSS.clear();

			inventory.at(usrIndexChoice)->SetQuantity(usrInptQnty);
		}
		this->SumInv();
		return;
	}

	// Dialogue to remove a specific item, then remove that specific item from the inventory
	void Inventory::RemoveItemFromInventory() {
		istringstream inSS;
		string usrIndexChoiceStr = "";
		unsigned int usrIndexChoice = 0;
		string usrInptQntyStr = "";

		if (inventory.size() == 0) {
			cout << "No items to remove." << endl;
		}
		else {
			this->PrintInventory();

			do {
				cout << "Remove which item #: ";
				getline(cin, usrIndexChoiceStr);
				inSS.str(usrIndexChoiceStr);
				inSS >> usrIndexChoice;
				inSS.clear();
			} while (!(usrIndexChoice < inventory.size()));

			inventory.erase(inventory.begin() + usrIndexChoice);
		}
		this->SumInv();
		return;
	}

	// Compute the inventory's Total Price
	void Inventory::SumInv() {
		int total = 0;

		for (int i = 0; i < inventory.size(); ++i) {
			total += inventory.at(i)->GetTotalValueAsPrice();
		}
		this->totalInvPriceDollars = total;

		return;
	}


int main() {
    Inventory* inventory;
    string usrInptOptn = "default";

	inventory = new Inventory;
    
    while (true) {
        // Get user choice		
        cout << "\nEnter (p)rint, (a)dd, (u)pdate, (r)emove, or (q)uit: ";		
        getline(cin >> ws, usrInptOptn);

        // Process user choice
        if (usrInptOptn.size() == 0) {
            continue;
        } else if (usrInptOptn.at(0) == 'p') {
            inventory->PrintInventory();
        } else if (usrInptOptn.at(0) == 'a') {
            inventory->AddItemToInventory();
        } else if (usrInptOptn.at(0) == 'u') {
            inventory->UpdateItemQtyInInventory();
        } else if (usrInptOptn.at(0) == 'r') {
            inventory->RemoveItemFromInventory();
        } else if (usrInptOptn.at(0) == 'q') {
            cout << "\nGood bye." << endl;
            break;
        }
    }

    return 0;
}
