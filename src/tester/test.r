#!Rscript
library(tidyverse)

data <- read_csv2(
    "output/test_vector_assign.txt",
    col_names = TRUE,
    n_max = Inf,
    progress = show_progress(),
    lazy = TRUE,
)
png("output.png", res = 300, width = 1920, height = 1080)

#yeeting scientific notation (more readable 4 normies)
options(scipen = 999)

#multing by 1000 to have results in ms instead of s
data$ft_assign <- as.numeric(data$ft_assign) * 10
data$std_assign <- as.numeric(data$std_assign) * 10
data$ft_assign_it <- as.numeric(data$ft_assign_it) * 10
data$std_assign_it <- as.numeric(data$std_assign_it) * 10

# ft assign
plot(
    data$size,    data$ft_assign,    type = "l",    col = "dodgerblue4",    lwd = 1,    xlab = "Vector size",    ylab = "Time (ms)",    ylim = c(0, 6), log="x",#    xlim = c(0, 50000)
)

# std assign
lines(
    data$size,    data$std_assign,    type = "l",    col = "lightblue",    lwd = 1,    lty = 1
)

# ft assign_it
lines(
    data$size,    data$ft_assign_it,    type = "l",    col = "forestgreen",    lwd = 1,    lty = 1
)

# std assign_it
lines(
    data$size,    data$std_assign_it,    type = "l",    col = "lightgreen",    lwd = 1,    lty = 1
)

title(
    main = "ft vs std on vector<>::assign methods"
)

legend(
    "topleft",
    legend = c("ft::assign(n, val)", "std::asssign(n, val)", "ft::assign(first, last)", "std::assign(first, last)"),
    col = c("dodgerblue4", "lightblue", "forestgreen", "lightgreen"),
    lwd = 1,
    lty = 1,
    # bg = "lightgrey",
    cex = 0.85
)

dev.off()
browseURL("output.png")