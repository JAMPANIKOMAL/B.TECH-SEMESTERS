#!/bin/bash

failed_login_count()
{
    journalctl | grep "Failed password" | wc -l
}

failed_login_count
