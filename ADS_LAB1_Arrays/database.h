#pragma once

struct Employer
{
	char name[20];
	char surname[20];
	char date_of_birth[10];
	char phone_number[10];

	Employer() {};
	Employer(	char name[], 
				char surname[], 
				char date_of_birth[], 
				char phone_number[]);
	void show_info_console();
	bool operator == (const Employer& e);

};



void add_element(Employer** employers_DB,
				int* capacity,
				int* employers_count,
				Employer e);


void DB_info(Employer employers_DB[],
			int employers_count);

int get_employer_index_inDB(Employer* employers_DB,
							int employers_count,
							Employer e);


void remove_employer(Employer employers_DB[],
					int capacity,
					int* employers_count,
					Employer e);

void replace_employer(	Employer *employers_DB,
							int size_DB,
							int employers_count,
							Employer old_employer,
							Employer new_employer);


char prompt_user_for_answer();

Employer enter_employer_info();
