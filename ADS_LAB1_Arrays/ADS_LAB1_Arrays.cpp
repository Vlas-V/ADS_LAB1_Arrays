// ADS_LAB1_Arrays.cpp

#include <iostream>
#include <string>
#include "database.h"

#define DEBUG


int main()
{

	// DB variables 
	const int size_DB = 100;
	int employers_count = 0;
	Employer employers_DB[size_DB];
	
	// API variables 
	char answer;
	Employer intermediate_employer_container;

	do
	{
		answer = prompt_user_for_answer();
		
		// Adding an element 
		if (answer == 'a')
		{
			intermediate_employer_container = enter_employer_info();
			add_element(employers_DB, size_DB, &employers_count, intermediate_employer_container);
			continue;
		}
		
		// Remove an employer from the db
		if (answer == 'r')
		{
			intermediate_employer_container = enter_employer_info();
			remove_employer(employers_DB, size_DB, &employers_count, intermediate_employer_container);
			continue;
		}

		if (answer == 'f')
		{
			intermediate_employer_container = enter_employer_info();
			
			int index = get_employer_index_inDB(employers_DB, size_DB, employers_count, intermediate_employer_container);

			if (index < 0)
			{
				std::cout << "There's no employer with such credentials." << std::endl;
				std::cout << index << std::endl;
			}
			else
			{
				employers_DB[index].show_info_console();
			}

			continue;
		}

		if (answer == 'c')
		{
			Employer new_employer;

			// Enter the info of the employer that you want to change 
			intermediate_employer_container = enter_employer_info();

			// Enter it's new info
			new_employer = enter_employer_info();

			replace_employer(employers_DB, size_DB, employers_count, intermediate_employer_container, new_employer);
			continue;
		}
		
		if (answer == 'i')
		{
			DB_info(employers_DB, size_DB, employers_count);
			continue;
		}

	} while (answer != 'e');


	return 0; 
}


