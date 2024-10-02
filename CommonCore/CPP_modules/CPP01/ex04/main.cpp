/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:50:20 by carmarqu          #+#    #+#             */
/*   Updated: 2024/09/28 17:54:45 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)//exec, nome do aqruivo, str a buscar, str a substituir
{
	if (argc != 4)
	{
		std::cout << "Wrong humber of arguments!" << std::endl;
		return (1);	
	}

	std::ifstream file(argv[1]);//abre arquivo como parametro para leitura
	std::ofstream(new_file);//declaro o arquivo novo (cria se n existe) 
	if (!file.is_open())
	{
		std::cout << "Error opening the file!" << std::endl;
		return (1);
	}
	std::string name_file(argv[1]);//copia o nome do argv[1] pra str
	name_file.append(".replace");//adiciona replace
	new_file.open(name_file.c_str());//abro o arquivo com o nome name_file. c_str = converte str em C-string
	
	
	std::string to_find_str(argv[2]); //string a ser reemplazada
	std::string replace_str(argv[3]); //string a ser adicionada
	std::string content;
	std::getline(file, content, '\0'); //le todo o arquivo (até o '\0') e armazena em content
	
	int pos; 
	while ((pos = content.find(to_find_str)) != -1)//le o arquivo e busca todas as aparições de to_find_str em content
	{
		content.erase(pos, to_find_str.length());
		content.insert(pos, replace_str);
	}
	new_file << content;
	new_file.close();
	file.close();
	return 0;
}