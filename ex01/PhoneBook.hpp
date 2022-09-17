/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:00:51 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/17 13:45:42 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "Contact.hpp"

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

class PhoneBook {
 public:
  PhoneBook();
  ~PhoneBook();
  int add_contact();
  int search_contact() const;

 private:
  Contact contacts_[8];
  int current_index_;
};

#endif