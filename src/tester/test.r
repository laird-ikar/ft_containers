#!Rscript
suppressPackageStartupMessages(library(tidyverse, warn.conflicts = FALSE, quietly = TRUE))
suppressPackageStartupMessages(library(ggplot2, warn.conflicts = FALSE, quietly = TRUE))
suppressPackageStartupMessages(library(ggpubr, warn.conflicts = FALSE, quietly = TRUE))

png("benchmark.png", res = 300, width = 4320, height = 2160, units = "px")

#yeeting scientific notation (more readable 4 normies)
options(scipen = 999)
options(warn=-1)

############## vector<>::assign methods ##############

data_assign <- read_csv2(
    "output/test_vector_assign.txt",
    col_names = TRUE,
    n_max = Inf,
    progress = show_progress(),
    lazy = TRUE,
    col_types = cols(),
    show_col_types = FALSE,
)

#multing by 2 to have results in ms instead of s (bc of 500 iterations in test)
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
scale_color_manual(values = c("ft::assign(n, val)" = "#138D75", "std::assign(n, val)" = "#76D7C4", "ft::assign(first, last)" = "#CB4335", "std::assign(first, last)" = "#E59866")) +
scale_x_log10() +
scale_y_log10() +
labs(x = "Vector size", y = "Time (ms)") +
# ylim(0, 3) +
theme_bw() +
ggtitle("vector<>::assign methods") +
theme(plot.title = element_text(hjust = 0.5))

############## vector<>::insert methods ##############

data_insert <- read_csv2(
    "output/test_vector_insert.txt",
    col_names = TRUE,
    n_max = Inf,
    progress = show_progress(),
    lazy = TRUE,
    col_types = cols(),
    show_col_types = FALSE,
)

#multing by X to have results in ms instead of s (bc of Y iterations in test)
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
scale_color_manual(values = c("ft::insert(pos, val)" = "#CB4335", "std::insert(pos, val)" = "#E59866", "ft::insert(pos, n, val)" = "#2980B9", "std::insert(pos, n, val)" = "#85C1E9", "ft::insert(pos, first, last)" = "#138D75", "std::insert(pos, first, last)" = "#76D7C4")) +
scale_x_log10() +
scale_y_log10() +
labs(x = "Vector size", y = "Time (ms)") +
# ylim(0, 3) +
theme_bw() +
ggtitle(label = "vector<>::insert methods", subtitle = "time x10 for (pos, n, val) prototype") +
theme(plot.title = element_text(hjust = 0.5), plot.subtitle = element_text(hjust = 0.5))

############# vector<>::erase methods ##############

data_erase <- read_csv2(
    "output/test_vector_erase.txt",
    col_names = TRUE,
    n_max = Inf,
    progress = show_progress(),
    lazy = TRUE,
    col_types = cols(),
)

#multing by X to have results in ms instead of s (bc of Y iterations in test)
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
scale_color_manual(values = c("ft::erase(pos)" = "#CB4335", "std::erase(pos)" = "#E59866", "ft::erase(first, last)" = "#2980B9", "std::erase(first, last)" = "#85C1E9")) +
scale_x_log10() +
scale_y_log10() +
labs(x = "Vector size", y = "Time (ms)") +
# ylim(0, 0.1) +
theme_bw() +
ggtitle(label = "vector<>::erase methods") +
theme(plot.title = element_text(hjust = 0.5))

############## vector<>::resize/reserve methods ##############

data_resize_reserve <- read_csv2(
    "output/test_vector_resize_reserve.txt",
    col_names = TRUE,
    n_max = Inf,
    progress = show_progress(),
    lazy = TRUE,
    col_types = cols(),
    show_col_types = FALSE,
)

#multing by X to have results in ms instead of s (bc of Y iterations in test)
data_resize_reserve$ft_resize <- as.numeric(data_resize_reserve$ft_resize) * 2
data_resize_reserve$std_resize <- as.numeric(data_resize_reserve$std_resize) * 2
data_resize_reserve$ft_reserve <- as.numeric(data_resize_reserve$ft_reserve) * 2
data_resize_reserve$std_reserve <- as.numeric(data_resize_reserve$std_reserve) * 2

#saving the plot in a variable
resize_reserve_plot <- ggplot(
    data = data_resize_reserve,
    aes(x = size, colour = Legend)
) +
geom_line(aes(y = ft_resize, colour = "ft::resize(n)"), linewidth = 1) +
geom_line(aes(y = std_resize, colour = "std::resize(n)"), linewidth = 0.5) +
geom_line(aes(y = ft_reserve, colour = "ft::reserve(n)"), linewidth = 1) +
geom_line(aes(y = std_reserve, colour = "std::reserve(n)"), linewidth = 0.5) +
scale_color_manual(values = c("ft::resize(n)" = "#CB4335", "std::resize(n)" = "#E59866", "ft::reserve(n)" = "#2980B9", "std::reserve(n)" = "#85C1E9")) +
scale_x_log10() +
scale_y_log10() +
labs(x = "Vector size", y = "Time (ms)") +
# ylim(0, 0.08) +
theme_bw() +
ggtitle(label = "vector<>::resize/reserve methods") +
theme(plot.title = element_text(hjust = 0.5))

############## Output ##############

#arranging all the plots in a grid on the same page
ggarrange(assign_plot, insert_plot, erase_plot, resize_reserve_plot, ncol = 2, nrow = 2)

dev.off()
browseURL("benchmark.png")