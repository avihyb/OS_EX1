SUBDIRS := q1 q2 q3 q4 q5 q6

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

.PHONY: $(SUBDIRS) clean

