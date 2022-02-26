# FT_PRINTF

## Goal of this project

The goal of this project is to recode `printf` function from libc.

## What did I learn from this project?
1. Using a variable number of arguments in a fuctions(variadic functions).
1. The exact work of printf function since it was nessecery to implement the following conversions: cspdiuxX%, with all the following flags: minus, zero, space, hash and plus.
1. The way to call a make rule from one makefile for another makefile (to compile `libft.a` and move it up, so I could use it on my project `ft_printf`).

## Usage

	$> make
