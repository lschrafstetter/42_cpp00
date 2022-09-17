/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:00:51 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/17 11:45:35 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

class PhoneBook {
 public:
  PhoneBook();
  ~PhoneBook();
  int add_contact();
  int search_contact() const;
  Contact contacts_[8];

 private:
  int current_index_;
};

#endif