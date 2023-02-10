#!Rscript
library(tidyverse)

data <- read_csv2(
    "output.txt",
    col_names = TRUE,
    n_max = Inf,
    progress = show_progress(),
    lazy = TRUE,
    col_types = cols(
        legend1 = col_double(),
        legend2 = col_double()
    )
)
png("output.png", res = 300, width = 1920, height = 1080)

# ft
plot(
    data$legend1,
    data$legend2,
    type = "l",
    col = "red",
    lwd = 2,
    xlab = "X",
    ylab = "Y"
)

# std
lines(
    data$legend1,
    data$legend2,
    type = "l",
    col = "lightblue",
    lwd = 5,
    lty = 6,
    xlab = "X",
    ylab = "Y"
)

title(
    main = "Legend",
    sub = "ft vs std on smth ig"
)

legend(
    "topleft",
    legend = c("ft", "std"),
#    col = "red":"lightblue",
    lwd = 2:5,
    border = "none",
    lty = 1:6,
    bty = "n",
    bg = "lightgrey",
    cex = 1.5
)

dev.off()
browseURL("output.png")