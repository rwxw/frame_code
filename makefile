myrule = target : ; @echo lqshishab

.PHONY: foo force

foo:
	frobnicate > foo

%: force 
	@$(MAKE) -f Makefile $@

force: ;

$(myrule)

%:
	@echo building foo