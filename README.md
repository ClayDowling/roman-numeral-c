# Roman Numeral Kata Clean Start

This is the first commit I made when I started this project.  It represents a
minimally working state: it can build the test suite, which consists of a
single test.

## What This Repository Is

The repository in this fresh state is a good minimalist example of the way
that *I* set up a project.  It's also good example for discussions about how
make works and the minimum viable requirements for setting up a C project
using the check library.

## What This Repository Isn't

This repository isn't a good starting point for your own work.  There are
things that are broken, and I've done some things that might be a bit tricky
and/or unsupportable in a production environment.  There are also incomplete
things.  For instance the src folder doesn't product a build artifact.  You
almost certainly want a build artifact, or there isn't much point in writing
tests.

This branch is also not a good example of how you should set up a project.  It
represents the way that *I* like to work.  If you're needing help setting up
the basic build ecosystem, you probably want a simpler structure unless you are
pairing with a more experienced developer who understands how and why this
setup works.

## Further Discovery

If you're looking at this for examples, there are additional resources you
should investigate:

http://c.learncodethehardway.org/book/ is a great introduction to the C
ecosystem, including Make.  The author is good at guiding you around some of
the ecosystem's more troublesome spots.  It also talks about a lot of seemingly
hidden features of C and make.  For instance, I am setting some curiously
named variables in my Makefile.  This book will show you *why* I'm doing that.

https://www.gnu.org/software/make/ contains more information on GNU Make.  It's
important that you understand what is going on in the Makefiles when you are
setting up your own project.  It's also very well written.

You should pay particular attention to how you build executables and libraries.

https://libcheck.github.io/check/doc/check_html/index.html is the manual for
the check library.  It is very well written and provides good examples.  In
particular it is very good about showing you how to use check in the larger
C and unix ecosystem.  Pay particular attention to their advice about the
different ways to structure your test suites and test cases.  I found that
reading this manual helped me a lot in getting my tests suite up and running,
as well as expanding it as I continued in the project.
