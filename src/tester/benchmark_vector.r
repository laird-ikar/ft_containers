#!Rscript
suppressPackageStartupMessages(library(tidyverse, warn.conflicts = FALSE, quietly = TRUE))
suppressPackageStartupMessages(library(ggplot2, warn.conflicts = FALSE, quietly = TRUE))
suppressPackageStartupMessages(library(ggpubr, warn.conflicts = FALSE, quietly = TRUE))

png("benchmark_v.png", res = 300, width = 4320, height = 4320, units = "px")

#yeeting scientific notation (more readable 4 normies)
options(scipen = 999)
options(warn=-1)

############## vector<>::assign methods ##############

data_assign <- read.csv2(
    "output/test_vector_assign.txt",
    header = TRUE,
    sep = ";",
    dec = "."
)

#multiplying by 2 to have results in ms instead of s (bc of 500 iterations in test)
data_assign$ft_assign <- as.numeric(data_assign$ft_assign) * 2
data_assign$std_assign <- as.numeric(data_assign$std_assign) * 2
data_assign$ft_assign_it <- as.numeric(data_assign$ft_assign_it) * 2
data_assign$std_assign_it <- as.numeric(data_assign$std_assign_it) * 2

#saving the plot in a variable
assign_plot <- ggplot(
    data = data_assign,
    aes(x = size, colour = legend)
)+ 
geom_line(aes(y = ft_assign, colour = "ft::assign(n, val)"), linewidth = 1) +
geom_line(aes(y = std_assign, colour = "std::assign(n, val)"), linewidth = 0.5) +
geom_line(aes(y = ft_assign_it, colour = "ft::assign(first, last)"), linewidth = 1) +
geom_line(aes(y = std_assign_it, colour = "std::assign(first, last)"), linewidth = 0.5) +
annotate("text", x = 10000, y = 1.5, label = "Ratio: 1:2.11", colour = "#2980B9", size = 5) +
annotate("text", x = 10000, y = 1, label = "Ratio: 1:0.66", colour = "#CB4335", size = 5) +
scale_color_manual(values = c("ft::assign(n, val)" = "#2980B9", "std::assign(n, val)" = "#85C1E9", "ft::assign(first, last)" = "#CB4335", "std::assign(first, last)" = "#E59866")) +
scale_x_log10() +
scale_y_log10() +
labs(x = "Vector size", y = "Time (ms)") +
# ylim(0, 3) +
theme_bw() +
ggtitle("vector<>::assign methods") +
theme(plot.title = element_text(hjust = 0.5))

############## vector<>::insert methods ##############

data_insert <- read.csv2(
    "output/test_vector_insert.txt",
    header = TRUE,
    sep = ";",
    dec = "."
)

#multiplying by X to have results in ms instead of s (bc of Y iterations in test)
data_insert$ft_insert <- as.numeric(data_insert$ft_insert) * 2
data_insert$std_insert <- as.numeric(data_insert$std_insert) * 2
data_insert$ft_insert_n <- as.numeric(data_insert$ft_insert_n) * 2
data_insert$std_insert_n <- as.numeric(data_insert$std_insert_n) * 2
data_insert$ft_insert_it <- as.numeric(data_insert$ft_insert_it) * 2
data_insert$std_insert_it <- as.numeric(data_insert$std_insert_it) * 2

#saving the plot in a variable
insert_plot <- ggplot(
    data = data_insert,
    aes(x = size, colour = Legend)
) +
geom_line(aes(y = ft_insert, colour = "ft::insert(pos, val)"), linewidth = 1) +
geom_line(aes(y = std_insert, colour = "std::insert(pos, val)"), linewidth = 0.5) +
geom_line(aes(y = ft_insert_n, colour = "ft::insert(pos, n, val)"), linewidth = 1) +
geom_line(aes(y = std_insert_n, colour = "std::insert(pos, n, val)"), linewidth = 0.5) +
geom_line(aes(y = ft_insert_it, colour = "ft::insert(pos, first, last)"), linewidth = 1) +
geom_line(aes(y = std_insert_it, colour = "std::insert(pos, first, last)"), linewidth = 0.5) +
annotate("text", x = 10000, y = 2.5, label = "Ratio: 1:1.76", colour = "#138D75", size = 5) +
annotate("text", x = 10000, y = 1.5, label = "Ratio: 1:1.32", colour = "#2980B9", size = 5) +
annotate("text", x = 10000, y = 0.9, label = "Ratio: 1:0.65", colour = "#CB4335", size = 5) +
scale_color_manual(values = c("ft::insert(pos, val)" = "#CB4335", "std::insert(pos, val)" = "#E59866", "ft::insert(pos, n, val)" = "#2980B9", "std::insert(pos, n, val)" = "#85C1E9", "ft::insert(pos, first, last)" = "#138D75", "std::insert(pos, first, last)" = "#76D7C4")) +
scale_x_log10() +
scale_y_log10() +
labs(x = "Vector size", y = "Time (ms)") +
# ylim(0, 3) +
theme_bw() +
ggtitle(label = "vector<>::insert methods", subtitle = "time x10 for (pos, n, val) prototype") +
theme(plot.title = element_text(hjust = 0.5), plot.subtitle = element_text(hjust = 0.5))

############# vector<>::erase methods ##############

data_erase <- read.csv2(
    "output/test_vector_erase.txt",
    header = TRUE,
    sep = ";",
    dec = "."
)

#multiplying by X to have results in ms instead of s (bc of Y iterations in test)
data_erase$ft_erase <- as.numeric(data_erase$ft_erase) * 2
data_erase$std_erase <- as.numeric(data_erase$std_erase) * 2
data_erase$ft_erase_it <- as.numeric(data_erase$ft_erase_it) * 2
data_erase$std_erase_it <- as.numeric(data_erase$std_erase_it) * 2

#saving the plot in a variable
erase_plot <- ggplot(
    data = data_erase,
    aes(x = size, colour = Legend)
) +
geom_line(aes(y = ft_erase, colour = "ft::erase(pos)"), linewidth = 1) +
geom_line(aes(y = std_erase, colour = "std::erase(pos)"), linewidth = 0.5) +
geom_line(aes(y = ft_erase_it, colour = "ft::erase(first, last)"), linewidth = 1) +
geom_line(aes(y = std_erase_it, colour = "std::erase(first, last)"), linewidth = 0.5) +
annotate("text", x = 10000, y = 0.04, label = "memmove spike (1:4.5)", colour = "#2980B9", size = 5) +
annotate("text", x = 10000, y = 0.09, label = "Ratio: 1:0.77", colour = "#2980B9", size = 5) +
annotate("text", x = 10000, y = 0.083, label = "Ratio: 1:0.7", colour = "#CB4335", size = 5) +
scale_color_manual(values = c("ft::erase(pos)" = "#CB4335", "std::erase(pos)" = "#E59866", "ft::erase(first, last)" = "#2980B9", "std::erase(first, last)" = "#85C1E9")) +
scale_x_log10() +
# scale_y_log10() +
labs(x = "Vector size", y = "Time (ms)") +
ylim(0, 0.1) +
theme_bw() +
ggtitle(label = "vector<>::erase methods") +
theme(plot.title = element_text(hjust = 0.5))

############## vector<>::resize/reserve methods ##############

data_resize_reserve <- read.csv2(
    "output/test_vector_resize_reserve.txt",
    header = TRUE,
    sep = ";",
    dec = "."
)

#multiplying by X to have results in ms instead of s (bc of Y iterations in test)
data_resize_reserve$ft_resize <- as.numeric(data_resize_reserve$ft_resize) * 1
data_resize_reserve$std_resize <- as.numeric(data_resize_reserve$std_resize) * 1
data_resize_reserve$ft_reserve <- as.numeric(data_resize_reserve$ft_reserve) * 1
data_resize_reserve$std_reserve <- as.numeric(data_resize_reserve$std_reserve) * 1

#saving the plot in a variable
resize_reserve_plot <- ggplot(
    data = data_resize_reserve,
    aes(x = size, colour = Legend)
) +
geom_line(aes(y = ft_resize, colour = "ft::resize(n)"), linewidth = 1) +
geom_line(aes(y = std_resize, colour = "std::resize(n)"), linewidth = 0.5) +
geom_line(aes(y = ft_reserve, colour = "ft::reserve(n)"), linewidth = 1) +
geom_line(aes(y = std_reserve, colour = "std::reserve(n)"), linewidth = 0.5) +
annotate("text", x = 10000, y = 0.03, label = "Ratio: 1:0.37", colour = "#2980B9", size = 5) +
annotate("text", x = 10000, y = 0.027, label = "Ratio: 1:0.42", colour = "#CB4335", size = 5) +
scale_color_manual(values = c("ft::resize(n)" = "#CB4335", "std::resize(n)" = "#E59866", "ft::reserve(n)" = "#2980B9", "std::reserve(n)" = "#85C1E9")) +
scale_x_log10() +
# scale_y_log10() +
labs(x = "Vector size", y = "Time (ms)") +
ylim(0, 0.036) +
theme_bw() +
ggtitle(label = "vector<>::resize/reserve methods") +
theme(plot.title = element_text(hjust = 0.5))

############# vector<>::operator= methods ##############

data_egal <- read.csv2(
    "output/test_vector_egal.txt",
    header = TRUE,
    sep = ";",
    dec = "."
)

#multiplying by X to have results in ms instead of s (bc of Y iterations in test)
data_egal$ft_egal <- as.numeric(data_egal$ft_egal) * 2
data_egal$std_egal <- as.numeric(data_egal$std_egal) * 2

#saving the plot in a variable
egal_plot <- ggplot(
    data = data_egal,
    aes(x = size, colour = Legend)
) +
geom_line(aes(y = ft_egal, colour = "ft::operator=(rhs)"), linewidth = 1) +
geom_line(aes(y = std_egal, colour = "std::operator=(rhs)"), linewidth = 0.5) +
annotate("text", x = 10000, y = 1, label = "Ratio: 1:0.58", colour = "#CB4335", size = 5) +
scale_color_manual(values = c("ft::operator=(rhs)" = "#CB4335", "std::operator=(rhs)" = "#E59866")) +
scale_x_log10() +
scale_y_log10() +
labs(x = "Vector size", y = "Time (ms)") +
# ylim(0, 5) +
theme_bw() +
ggtitle(label = "vector<>::operator= method") +
theme(plot.title = element_text(hjust = 0.5))

############## vector<>::vector methods (constructors) ##############

data_construct <- read.csv2(
    "output/test_vector_construct.txt",
    header = TRUE,
    sep = ";",
    dec = "."
)

#multiplyng by X to have results in ms instead of s (bc of Y iterations in test)
data_construct$ft_construct <- as.numeric(data_construct$ft_construct) * 2
data_construct$std_construct <- as.numeric(data_construct$std_construct) * 2
data_construct$ft_construct_range <- as.numeric(data_construct$ft_construct_range) * 2
data_construct$std_construct_range <- as.numeric(data_construct$std_construct_range) * 2

#saving the plot in a variable
construct_plot <- ggplot(
    data = data_construct,
    aes(x = size, colour = Legend)
) +
geom_line(aes(y = ft_construct, colour = "ft::vector(n)"), linewidth = 1) +
geom_line(aes(y = std_construct, colour = "std::vector(n)"), linewidth = 0.5) +
geom_line(aes(y = ft_construct_range, colour = "ft::vector(first, last)"), linewidth = 1) +
geom_line(aes(y = std_construct_range, colour = "std::vector(first, last)"), linewidth = 0.5) +
annotate("text", x = 10000, y = 10, label = "Ratio: 1:0.1", colour = "#2980B9", size = 5) +
annotate("text", x = 10000, y = 5, label = "Ratio: 1:0.34", colour = "#CB4335", size = 5) +
scale_color_manual(values = c("ft::vector(n)" = "#CB4335", "std::vector(n)" = "#E59866", "ft::vector(first, last)" = "#2980B9", "std::vector(first, last)" = "#85C1E9")) +
scale_x_log10() +
scale_y_log10() +
labs(x = "Vector size", y = "Time (ms)") +
# ylim(0, 35) +
theme_bw() +
ggtitle(label = "vector<>::vector methods (constructors)") +
theme(plot.title = element_text(hjust = 0.5))

############## Output ##############

#arranging all the plots in a grid on the same page
ggarrange(assign_plot, insert_plot, erase_plot, resize_reserve_plot, egal_plot, construct_plot, ncol = 2, nrow = 3)

dev.off()
browseURL("benchmark_v.png")