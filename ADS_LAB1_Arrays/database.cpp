#include "database.h"
#include <iostream>
#include <string>

Employer::Employer(char name[], char surname[], char date_of_birth[], char phone_number[])
{
	strncpy_s(this->name, name, sizeof(name));
	strncpy_s(this->surname, surname, sizeof(surname));
	strncpy_s(this->date_of_birth, date_of_birth, sizeof(date_of_birth));
	strncpy_s(this->phone_number, phone_number, sizeof(phone_number));
}

void Employer::show_info_console()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Surname: " << surname << std::endl;
	std::cout << "Date of birth (dd:mm:yyyy format): " << date_of_birth << std::endl;
	std::cout << "Phone Number (10 digits): " << phone_number << std::endl;
	std::cout << std::endl << std::endl;
}

bool Employer::operator == (const Employer& e)
{
	if (strcmp(name, e.name) == 0
		&& strcmp(surname, e.surname) == 0
		&& strcmp(date_of_birth, e.date_of_birth) == 0
		&& strcmp(phone_number, e.phone_number) == 0)
	{
		return true;
	}
	else
		return false;
}

void add_element(Employer** employers_DB,
				int* capacity,
				int* employers_count,
				Employer e)
{

	// Check if there's still enough space
	if (*employers_count < *capacity)
	{
		//*employers_DB[*employers_count] = e; // the paranticies?? 
		*(*employers_DB + *employers_count) = e;
	}
	else // Resize the array othewise
	{
		Employer* new_employer_DB = new Employer[(*employers_count) + 1];

		for (int i = 0; i < *employers_count; i++)
		{
			new_employer_DB[i] = (*employers_DB)[i];
		}

		new_employer_DB[*employers_count] = e;
		
		delete[] *employers_DB;
		*employers_DB = new_employer_DB;
		
		(*capacity)++;

	}

	//employers_DB[*employers_count] = e;
	(*employers_count)++;

}


void DB_info(Employer employers_DB[],
			int employers_count)
{
	if (employers_count == 0)
	{
		std::cout << "No records in the database." << std::endl;
		return;
	}

	for (int i = 0; i < employers_count; i++)
	{
		std::cout << i + 1 << std::endl;
		employers_DB[i].show_info_console();
	}
}


int get_employer_index_inDB(Employer *employers_DB,
							int employers_count,
							Employer e)
{

	for (int i = 0; i < employers_count; i++) if (employers_DB[i] == e) return i;

	return -1;
}


void remove_employer(Employer employers_DB[],
					int capacity,
					int* employers_count,
					Employer e)
{

	// What should I do? 

	// First let's find the employers index 
	int index = get_employer_index_inDB(employers_DB, *employers_count, e);

	// The employer hasn't been found 
	if (index < 0)
	{
		std::cout << "The employer with such credentials hasn't been found." << std::endl;
		std::cout << index << std::endl;
		return;
	}


	// Just shift of of the element after the founc one 
	for (int i = index; i < *employers_count - 1; i++)
	{
		employers_DB[i] = employers_DB[i + 1];
	}

	(*employers_count)--;

}


void replace_employer(Employer *employers_DB,
						int size_DB,
						int employers_count,
						Employer old_employer,
						Employer new_employer)
{
	int index_of_old_employer = get_employer_index_inDB(employers_DB, employers_count, old_employer);

	if (index_of_old_employer < 0)
	{
		std::cout << "There's no employers with such credentials." << std::endl;
		std::cout << index_of_old_employer << std::endl;
		return;
	}

	*(employers_DB + index_of_old_employer) = new_employer;

}


char prompt_user_for_answer()
{
	char answer;

	// Privide the user with the API options 
	std::cout << "Choose what you want to do, type the according letter, and press Enter: " << std::endl;

	std::cout << "Add an employer to the db - a" << std::endl;
	std::cout << "Remove an employer for the db  - r" << std::endl;
	std::cout << "Retrive (find) information about an employer - f" << std::endl;
	std::cout << "Change an employer's info - c" << std::endl;
	std::cout << "Show the database info - i" << std::endl;

	std::cout << "Exit - e" << std::endl << std::endl << std::endl;

	// Promt the user for the answer 
	std::cin >> answer;

	return answer;
}


Employer enter_employer_info()
{
	Employer intermediate_employer_container;

	std::cout << "Enter the employer info:\n";

	std::cout << "Name: ";
	std::cin >> intermediate_employer_container.name;

	std::cout << "Surname: ";
	std::cin >> intermediate_employer_container.surname;

	std::cout << "Date of birth (dd:mm:yyyy format): ";
	std::cin >> intermediate_employer_container.date_of_birth;

	std::cout << "Phone Number (10 digits): ";
	std::cin >> intermediate_employer_container.phone_number;

	std::cout << std::endl << std::endl;

	return intermediate_employer_container;
}

