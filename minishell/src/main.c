/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:51:26 by lglauch           #+#    #+#             */
/*   Updated: 2024/05/02 19:55:56 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("\n");
    printf("   _   _   _   _   _   _   _   _   _   \n");
    printf("  / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ \n");
    printf(" ( M | I | N | I | S | H | E | L | L )\n");
    printf("  \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \n");
    printf("********************************\n");
    printf("\nWelcome to Minishell by \033]8;;https://github.com/lglauch\alglauch\033]8;;\a\n\n");
    printf("********************************\n");
    while(1) {
        printf("🐚  ");
        read = getline(&line, &len, stdin);

        if (read == -1) {
            perror("getline");
            exit(EXIT_FAILURE);
        }
        line[strcspn(line, "\n")] = 0;
        if(strcmp(line, "exit") == 0) {
            break;
        }
    }
    free(line);
    return 0;
}