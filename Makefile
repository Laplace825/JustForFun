build:
	@bash ./scripts/build.sh \
		-DCMAKE_CXX_FLAGS="-std=c++2c -stdlib=libc++ -Wall -Wextra -Werror -Wno-unused-variable"\
		-DCMAKE_BUILD_TYPE=Release

clean:
	@bash ./scripts/clean.sh

run:
	@bash ./scripts/run.sh

all: build run


.PHONY: build clean run all

