/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:57:19 by carmarqu          #+#    #+#             */
/*   Updated: 2024/09/21 18:15:24 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
	#define CONTACT_HPP
	
	#include <iostream>
	#include <string>
	#include <cctype>
	#include <algorithm>
	#include <iomanip>

	class Contact{
	
	    private:
	        std::string _fname;
	        std::string _lname;
	        std::string _nickname;
	        std::string _phone;
	        std::string _secret;
	
	    public:
	        Contact(void); //construtor tem que ser chamado com Contact::contact
	        ~Contact(void);//destrutor
			//getter devolvel o valor da variavel e setters dao o valor a variavel
	        std::string     get_fname(void);
	        std::string     get_lname(void);
	        std::string     get_nickname(void);
	        std::string     get_phone(void);
	        std::string     get_secret(void); 
	        void			set_fname(void);
	        void			set_lname(void);
	        void			set_nickname(void);
	        void			set_phone(void);
	        void			set_secret(void);      
	};

#endif