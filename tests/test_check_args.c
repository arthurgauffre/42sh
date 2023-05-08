/*
** EPITECH PROJECT, 2023
** test 42sh
** File description:
** test_check_args
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

Test(shell_basic, simple_command) {
    int status;
    pid_t pid = fork();
    cr_assert_neq(pid, -1, "fork() failed");

    if (pid == 0) { // child process
        execl("./42sh", "./42sh", "-c", "ls", NULL);
        exit(EXIT_FAILURE);
    } else { // parent process
        waitpid(pid, &status, 0);
        cr_assert(WIFEXITED(status), "Child process did not terminate normally");
        cr_assert_eq(WEXITSTATUS(status), 0, "Child process returned non-zero exit status");
    }
}

Test(shell_basic, command_with_arguments) {
    int status;
    pid_t pid = fork();
    cr_assert_neq(pid, -1, "fork() failed");

    if (pid == 0) { // child process
        execl("./42sh", "./42sh", "-c", "ls -l", NULL);
        exit(EXIT_FAILURE);
    } else { // parent process
        waitpid(pid, &status, 0);
        cr_assert(WIFEXITED(status), "Child process did not terminate normally");
        cr_assert_eq(WEXITSTATUS(status), 0, "Child process returned non-zero exit status");
    }
}

Test(shell_basic, cd_command) {
    int status;
    pid_t pid = fork();
    cr_assert_neq(pid, -1, "fork() failed");

    if (pid == 0) { // child process
        execl("./42sh", "./42sh", "-c", "cd /tmp && pwd", NULL);
        exit(EXIT_FAILURE);
    } else { // parent process
        waitpid(pid, &status, 0);
        cr_assert(WIFEXITED(status), "Child process did not terminate normally");
        cr_assert_eq(WEXITSTATUS(status), 0, "Child process returned non-zero exit status");
    }
}