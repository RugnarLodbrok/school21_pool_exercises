#!/bin/bash
norminette -R CheckForbiddenSourceHeader $(git ls-files)
