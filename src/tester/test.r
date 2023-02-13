#!Rscript
library(tidyverse)
library(ggplot2)
library(ggpubr)

png("output.png", res = 300, width = 1920, height = 1080, units = "px")

#yeeting scientific notation (more readable 4 normies)
options(scipen = 999)

############## vector<>::assign methods ##############

data_assign <- read_csv2(
    "output/test_vector_assign.txt",
    col_names = TRUE,
    n_max = Inf,
    progress = show_progress(),
    lazy = TRUE,
)

#multing by 2 to have results in ms instead of s (bc of 500 iterations in test)
data_assign$ft_assign <- as.numeric(data_assign$ft_assign) * 2
data_assign$std_assign <- as.numeric(data_assign$std_assign) * 2
data_assign$ft_assign_it <- as.numeric(data_assign$ft_assign_it) * 2
data_assign$std_assign_it <- as.numeric(data_assign$std_assign_it) * 2

# assign_plot <- ggplot(
#     data = data_assign,
#     aes(x = size, colour = legend)
# )+ 
# geom_line(aes(y = ft_assign, colour = "ft::assign(n, val)"), linewidth = 1) +
# geom_line(aes(y = std_assign, colour = "std::assign(n, val)"), linewidth = 0.5) +
# geom_line(aes(y = ft_assign_it, colour = "ft::assign(first, last)"), linewidth = 1) +
# geom_line(aes(y = std_assign_it, colour = "std::assign(first, last)"), linewidth = 0.5) +
# scale_x_log10() +
# labs(x = "Vector size", y = "Time (ms)") +
# ylim(0, 3) +
# theme_bw() +
# ggtitle("vector<>::assign methods") +
# theme(plot.title = element_text(hjust = 0.5))

# ############## vector<>::insert methods ##############

data_insert <- read_csv2(
    "output/test_vector_insert.txt",
    col_names = TRUE,
    n_max = Inf,
    progress = show_progress(),
    lazy = TRUE,
)

#multing by X to have results in ms instead of s (bc of Y iterations in test)
data_insert$ft_insert <- as.numeric(data_insert$ft_insert) * 2
data_insert$std_insert <- as.numeric(data_insert$std_insert) * 2
data_insert$ft_insert_n <- as.numeric(data_insert$ft_insert_n) * 2
data_insert$std_insert_n <- as.numeric(data_insert$std_insert_n) * 2
data_insert$ft_insert_it <- as.numeric(data_insert$ft_insert_it) * 2
data_insert$std_insert_it <- as.numeric(data_insert$std_insert_it) * 2

#create a ggplot object according to the 20 following lines
# insert_plot <- 
ggplot(
    data = data_insert,
    aes(x = size, colour = legend)
) +
geom_line(aes(y = ft_insert, colour = "ft::insert(n, val)"), linewidth = 1) +
geom_line(aes(y = std_insert, colour = "std::insert(n, val)"), linewidth = 0.5) +
geom_line(aes(y = ft_insert_n, colour = "ft::insert(n, n, val)"), linewidth = 1) +
geom_line(aes(y = std_insert_n, colour = "std::insert(n, n, val)"), linewidth = 0.5) +
geom_line(aes(y = ft_insert_it, colour = "ft::insert(first, last)"), linewidth = 1) +
geom_line(aes(y = std_insert_it, colour = "std::insert(first, last)"), linewidth = 0.5) +
scale_x_log10() +
labs(x = "Vector size", y = "Time (ms)") +
ylim(0, 10) +
theme_bw() +
ggtitle("vector<>::insert methods") +
theme(plot.title = element_text(hjust = 0.5))

# ggarrange(assign_plot, insert_plot, ncol = 1, nrow = 2)










dev.off()
browseURL("output.png")