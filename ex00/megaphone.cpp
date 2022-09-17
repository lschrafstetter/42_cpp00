/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:44:41 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/16 12:58:14 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv) {
  if (argc <= 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    std::exit(0);
  }
  for (int i = 1; i < argc; i++) {
    for (char *str = argv[i]; *str; str++) {
      std::cout << (char)std::toupper(*str);
    }
  }
}