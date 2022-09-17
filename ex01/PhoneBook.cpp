/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:00:36 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/17 13:38:20 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() { this->current_index_ = 0; }

PhoneBook::~PhoneBook() {}

// asks for input to store in "input". Repeats if string is empty and aborts if
// it encouters EOF (ctrl + d)
static int add_contact_input_loop(std::string &input) {
  while (1) {
    if (!getline(std::cin, input)) return EXIT_FAILURE;
    if (input.empty())
      std::cout << "Not accepting empty input. Try again." << std::endl;
    else
      return EXIT_SUCCESS;
  }
}

static bool is_number(std::string str) {
  for (int i = 0; str[i]; i++)
    if (!isdigit(str[i])) return false;
  return true;
}

int PhoneBook::add_contact() {
  Contact temp;
  std::string input;

  std::cout << "Enter the contacts first name:" << std::endl;
  if (add_contact_input_loop(input)) return EXIT_FAILURE;
  temp.set_first_name(input);

  std::cout << "Enter the contacts last name:" << std::endl;
  if (add_contact_input_loop(input)) return EXIT_FAILURE;
  temp.set_last_name(input);

  std::cout << "Enter the contacts nickname:" << std::endl;
  if (add_contact_input_loop(input)) return EXIT_FAILURE;
  temp.set_nickname(input);

  std::cout << "Enter the contacts phone number:" << std::endl;
  while (1) {
    if (add_contact_input_loop(input)) return EXIT_FAILURE;
    if (is_number(input) == true) break;
    std::cout << input << " is not a number. Try again." << std::endl;
  }
  temp.set_phone_number(input);

  std::cout << "Enter the contacts darkest secret:" << std::endl;
  if (add_contact_input_loop(input)) return EXIT_FAILURE;
  temp.set_darkest_secret(input);

  this->contacts_[this->current_index_] = temp;
  this->current_index_ = (this->current_index_ + 1) % 8;
  return EXIT_SUCCESS;
}

std::string truncate(std::string str) {
  if (str.length() > 10) return str.substr(0, 9) + ".";
  return str;
}

// Prints one contacts information in the search table
static void search_contact_print_line(Contact contact, int i) {
  std::cout << std::right << std::setw(10) << i << "|";
  std::cout << std::right << std::setw(10) << truncate(contact.get_first_name())
            << "|";
  std::cout << std::right << std::setw(10) << truncate(contact.get_last_name())
            << "|";
  std::cout << std::right << std::setw(10) << truncate(contact.get_nickname())
            << std::endl;
}

int PhoneBook::search_contact() const {
  std::string input;

  // Check if phone book is empty
  if (this->contacts_[0].get_first_name().empty()) {
    std::cout << "Phone book is empty. Fill it first" << std::endl;
    return EXIT_SUCCESS;
  }

  // Print a contact table: right aligned, truncated at 10 characters
  std::cout << std::right << std::setw(10) << "Index";
  std::cout << "|";
  std::cout << std::right << std::setw(10) << "First name";
  std::cout << "|";
  std::cout << std::right << std::setw(10) << "Last name";
  std::cout << "|";
  std::cout << std::right << std::setw(10) << "Nickname" << std::endl;
  for (int i = 0; i < 8; i++) {
    if (this->contacts_[i].get_first_name().empty() == false) {
      search_contact_print_line(this->contacts_[i], i);
    }
  }

  // Get input to show a specific index of the phone book
  std::cout << "Enter an index to show all info of a contact:" << std::endl;
  std::cout << "Enter an index to show all info of a contact:" << std::endl;
  while (1) {
    if (!getline(std::cin, input)) return EXIT_FAILURE;
    if (input.empty())
      std::cout << "Not accepting empty input. Try again." << std::endl;
    else {
      int index = input[0] - 48;
      if (input[1] || index < 0 || index > 7 ||
          this->contacts_[index].get_first_name().empty())
        std::cout << "Invalid index. Try again." << std::endl;
      else
        break;
    }
  }

  // Print contact info
  std::cout << std::endl << std::left << std::setw(20) << "FIRST NAME: "
  					<< this->contacts_[std::stoi(input)].get_first_name()
						<< std::endl
  					<< std::setw(20) << "LAST NAME: "
  					<< this->contacts_[std::stoi(input)].get_last_name()
						<< std::endl
  					<< std::setw(20) << "NICKNAME: "
  					<< this->contacts_[std::stoi(input)].get_nickname()
						<< std::endl
  					<< std::setw(20) << "PHONE NUMBER: "
  					<< this->contacts_[std::stoi(input)].get_phone_number()
            << std::endl
  					<< std::setw(20) << "DARKEST SECRET: "
  					<< this->contacts_[std::stoi(input)].get_darkest_secret()
            << std::endl << std::endl;
  return EXIT_SUCCESS;
}
