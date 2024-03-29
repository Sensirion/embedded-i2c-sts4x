driver_dir := ..
mux_dir := ../i2c-mux-testbed

i2c_mux_sources = ${mux_dir}/i2c_mux.h ${mux_dir}/i2c_mux.c
common_sources = ${driver_dir}/sensirion_config.h ${driver_dir}/sensirion_common.h ${driver_dir}/sensirion_common.c
i2c_sources = ${driver_dir}/sensirion_i2c_hal.h ${driver_dir}/sensirion_i2c.h ${driver_dir}/sensirion_i2c.c
sensirion_test_sources = sensirion_test_setup.cpp ${i2c_mux_sources}

sw_i2c_dir := ${driver_dir}/sample-implementations/GPIO_bit_banging

hw_i2c_impl_src = ${driver_dir}/sample-implementations/linux_user_space/sensirion_i2c_hal.c
sw_i2c_impl_src = ${sw_i2c_dir}/sample-implementations/linux_user_space/sensirion_i2c_gpio.c ${sw_i2c_dir}/sensirion_i2c_hal.c

sts4x_sources = ${driver_dir}/sts4x_i2c.h ${driver_dir}/sts4x_i2c.c

CXXFLAGS ?= $(CFLAGS) -fsanitize=address -I${mux_dir} -I${driver_dir} -I${sw_i2c_dir}
ifdef CI
	CXXFLAGS += -Werror
endif
LDFLAGS ?= -lasan -lstdc++ -lCppUTest -lCppUTestExt

.PHONY: clean test


sts4x_test_binaries := sts4x-test-hw_i2c sts4x-test-sw_i2c

all: ${sts4x_test_binaries}

sts4x-test-hw_i2c: sts4x_i2c_test.cpp ${sts4x_sources} ${sensirion_test_sources} ${i2c_sources} ${hw_i2c_impl_src} ${common_sources}
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

sts4x-test-sw_i2c: sts4x_i2c_test.cpp ${sts4x_sources} ${sensirion_test_sources} ${i2c_sources} ${sw_i2c_impl_src} ${common_sources}
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

test: ${sts4x_test_binaries}
	set -ex; for test in ${sts4x_test_binaries}; do echo $${test}; ./$${test}; echo; done;

clean:
	$(RM) ${sts4x_test_binaries}
