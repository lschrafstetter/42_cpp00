/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:44:41 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/17 13:18:11 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv) {
  if (argc <= 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    std::exit(EXIT_SUCCESS);
  }
  for (int i = 1; i < argc; i++) {
    for (int j = 0; argv[i][j]; j++) {
      if (argv[i][j] == '\\' && argv[i][j + 1] == 'n') {
        std::cout << std::endl;
        j++;
      } else
        std::cout << (char)std::toupper(argv[i][j]);
    }
  }
  std::cout << std::endl;
  return (EXIT_SUCCESS);
}