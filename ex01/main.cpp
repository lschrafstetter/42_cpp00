/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:00:26 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/17 11:56:53 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main(void) {
  PhoneBook phone_book;
  std::string input;

  std::cout << "Welcome to your Phone Book!" << std::endl;
  std::cout << "Please enter ADD, SEARCH or EXIT" << std::endl;
  while (getline(std::cin, input)) {
    if (input == "ADD") {	
      if (phone_book.add_contact()) {
				std::cout << "Failed adding contact! Exiting!" << std::endl;
				return EXIT_FAILURE;
			}
		}
    else if (input == "SEARCH") {
			if (phone_book.search_contact()) {
				std::cout << "Cancelled search! Exiting!" << std::endl;
				return EXIT_FAILURE;	
			}
		}
    else if (input == "EXIT")
      break;
		else
			std::cout << "Invalid input! Try again!" << std::endl;
    std::cout << "Please enter ADD, SEARCH or EXIT" << std::endl;
  }
  std::cout << "Byebye!" << std::endl;
}