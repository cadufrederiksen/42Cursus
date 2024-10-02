/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:04:10 by carmarqu          #+#    #+#             */
/*   Updated: 2024/09/21 20:27:28 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
	#define PHONEBOOK_H
	
	#include "Contact.hpp"

	class PhoneBook{
		
		private:
			Contact	_contact[8];
			int 	index;
			int		nr_contact;
			
		public:
			PhoneBook(void);
			~PhoneBook(void);
			
			void add(void);
			void search(void);
			void print(Contact contact);
			std::string check_str(std::string str);
			
			Contact get_contact(int index);
	};
	
	
#endif